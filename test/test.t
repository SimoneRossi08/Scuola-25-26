#!/usr/bin/perl
use strict;
use warnings;

# -------------------------------------------------
#   Esempio Perl: saluta l'utente e conta le lettere
# -------------------------------------------------

print "Come ti chiami? ";
my $nome = <STDIN>;
chomp $nome;          # rimuove il newline finale

my $lunghezza = length($nome);

print "\nCiao, $nome!\n";
print "Il tuo nome ha $lunghezza lettere.\n";

# mostra la data corrente
my @t = localtime();
printf "Data e ora: %02d/%02d/%04d %02d:%02d:%02d\n",
       $t[3], $t[4]+1, $t[5]+1900, $t[2], $t[1], $t[0];