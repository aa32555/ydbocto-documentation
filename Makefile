all:
	pdflatex main.tex
	bibtex main
	pdflatex main.tex
html:
	htlatex main
	bibtex main
	htlatex main
clean:
	rm -f *.aux *.log *.synctex.gz *.pdf *.bbl *.blg
	rm -f *.4ct *.4tc *.css *.html *.idv *.dvi *.lg  *.xref
	rm -f *.tmp

