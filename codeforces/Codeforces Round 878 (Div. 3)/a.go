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
		var n int
		Fscan(in, &n)
		var s string
		Fscan(in, &s)

		var head byte = 0
		var ans string
		for i := range s {
			if head != 0 {
				if head != s[i] {
					continue
				} else {
					ans += string(head)
					head = 0
				}
			} else {
				head = s[i]
			}
		}

		if head != 0 {
			ans += string(head)
		}

		Fprintln(out, ans)
	}
}

func main() {
	sol(os.Stdin, os.Stdout)
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
