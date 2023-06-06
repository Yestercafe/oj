package main

import (
	. "fmt"
	"os"
	"io"
	"bufio"
)

func sol(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T int
	for Fscan(in, &T); T > 0; T-- {
		var n, m int
		Fscan(in, &n, &m)

		for i := 1; i < n; i += 2 {
			for j := 0; j < m; j++ {
				Fprint(out, i*m+j+1, " ")
			}
			Fprintln(out)
		}
		for i := 0; i < n; i += 2 {
			for j := 0; j < m; j++ {
				Fprint(out, i*m+j+1, " ")
			}
			Fprintln(out)
		}
	}
}

func main() {
	sol(os.Stdin, os.Stdout)
}
