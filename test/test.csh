#!/bin/csh
# test.csh - semplice helper C-shell per compilare ed eseguire programmi C
# Uso: test.csh [-h] [-l] [-c] [-r] file.c
#  -h    mostra questo help
#  -l    lista i file .c nella directory corrente
#  -c    compila il file C (genera ./<basename>)
#  -r    compila ed esegue il file C

if ($#argv == 0) then
	echo "Uso: $0 [-h] [-l] [-c] [-r] file.c"
	exit 1
endif

set opt_compile = 0
set opt_run = 0
set opt_list = 0

# parse degli argomenti (semplice)
while ( $#argv > 0 )
	switch ($argv[1])
		case -h:
			echo "test.csh - helper per compilare/eseguire C"
			echo "Usage: $0 [-h] [-l] [-c] [-r] file.c"
			echo "  -h show help"
			echo "  -l list .c files in current dir"
			echo "  -c compile only"
			echo "  -r compile and run"
			exit 0
			breaksw
		case -l:
			set opt_list = 1
			shift
			breaksw
		case -c:
			set opt_compile = 1
			shift
			breaksw
		case -r:
			set opt_run = 1
			shift
			breaksw
		default:
			break
	endsw
	if ($argv[1] == "" ) then
		break
	endif
end

if ($opt_list == 1) then
	echo "File .c nella directory corrente:"
	foreach f (*.c)
		if ( -f $f ) then
			echo "  $f"
		endif
	end
	exit 0
endif

# scegli il file C tra gli argomenti rimanenti
set cfile = ""
if ($#argv >= 1) then
	set cfile = $argv[$#argv]
endif

if ( "$cfile" == "" ) then
	echo "Errore: nessun file .c specificato"
	exit 1
endif

if ( ! -f $cfile ) then
	echo "Errore: file '$cfile' non trovato"
	exit 1
endif

set gccpath = `which gcc 2>/dev/null`
if ( "$gccpath" == "" ) then
	echo "Errore: gcc non è installato o non è nel PATH"
	exit 1
endif

# nome dell'eseguibile
set base = `basename $cfile .c`
set exe = "./${base}"

if ( $opt_compile == 0 && $opt_run == 0 ) then
	# default: compila ed esegui
	set opt_run = 1
endif

if ( $opt_compile || $opt_run ) then
	echo "Compilazione: gcc -Wall -Wextra -g -o $exe $cfile"
	gcc -Wall -Wextra -g -o $exe $cfile
	if ( $status != 0 ) then
		echo "Compilazione fallita (exit $status)."
		exit $status
	endif
	echo "Compilazione completata: $exe"
endif

if ( $opt_run ) then
	echo "----- Esecuzione di $exe -----"
	$exe
	set rc = $status
	echo "----- Program terminated with exit code: $rc -----"
	exit $rc
endif

exit 0
