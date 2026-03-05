@echo off
REM -------------------------------------------------
REM   Esempio di script batch che chiede il nome
REM   e mostra la data/ora corrente.
REM -------------------------------------------------

echo Ciao! Come ti chiami?
set /p nome=

echo.
echo Piacere di conoscerti, %nome%!
echo La data e ora attuali sono:
date /t
time /t

echo.
pause