#!/usr/bin/env python3
"""
Esempio semplice: stampa un messaggio e, se fornito,
stampa anche il primo argomento passato dalla riga di comando.
"""
import sys


def main(argv=None):
	argv = argv or sys.argv[1:]
	print("Ciao — questo è un esempio semplice.")
	if argv:
		print("Argomento ricevuto:", argv[0])
	else:
		print("Nessun argomento fornito.")


if __name__ == '__main__':
	main()

