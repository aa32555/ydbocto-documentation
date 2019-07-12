all:
	pdflatex main.tex
	bibtex main
	pdflatex main.tex
clean:
	rm -f *.aux *.log *.synctex.gz *.pdf *.bbl *.blg

