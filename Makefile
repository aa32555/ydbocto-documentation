all: targets
	lualatex main.tex
	bibtex main
	lualatex main.tex
html: targets
	htlatex main
	bibtex main
	htlatex main
	rm -rf html
	mkdir html
	mv *.css *.html html/
clean:
	rm -f *.aux *.log *.synctex.gz *.pdf *.bbl *.blg
	rm -f *.4ct *.4tc *.css *.html *.idv *.dvi *.lg  *.xref
	rm -f *.tmp

targets: main.tex biblo.bib
