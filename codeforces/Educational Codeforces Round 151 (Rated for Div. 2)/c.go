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
		var s_ string
		Fscan(in, &s_)
		s := []rune(s_)
		var m int
		Fscan(in, &m)
		var l_, r_ string
		Fscan(in, &l_, &r_)
		l, r := []rune(l_), []rune(r_)
		used := make([]int, m)
		for i := range l {
			for d := '0'; d < l[i]; d++ {
				a := int(d - '0')
			 	used[i] |= 1 << a
			}
			for d := r[i] + 1; d <= '9'; d++ {
				a := int(d - '0')
				used[i] |= 1 << a
			}
		}
		full := (1 << 10) - 1

		j := 0
		for _, c := range s {
			if j == m {
				break
			}
			if l[j] <= c && c <= r[j] {
				used[j] |= 1 << (c - '0')
				
				if used[j] == full {
					j++
				}
			}
		}

		if j == m {
			Fprintln(out, "NO")
		} else {
			Fprintln(out, "YES")
		}
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
