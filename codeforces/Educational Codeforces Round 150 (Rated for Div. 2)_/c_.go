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
		sum := 0
		n := len(s)
		vals := map[rune]int {
			'A': 1,
			'B': 10,
			'C': 100,
			'D': 1000,
			'E': 10000,
		}
		var maxx rune = 'A' - 1
		maxs := make([]rune, n)
		for i := len(s) - 1; i >= 0; i-- {
			maxs[i] = maxx
			if s[i] >= maxx {
				sum += vals[s[i]]
			} else {
				sum -= vals[s[i]]
			}
			maxx = maxr(maxx, s[i])
		}
		
		ans := sum
		prefix := []int{0, 0, 0, 0, 0}
		var ansI int
		var ansC rune
		for i, b := range s {
			for c := 'A'; c <= 'E'; c++ {
				if c == b { continue }
				lans := sum
				m := maxs[i]

				if c <= b && b <= m {
					lans += vals[b] - vals[c]
				} else if c <= m && m <= b {
					lans += -vals[b] - vals[c]
					lans += (prefix[b - 'A'] - prefix[c - 'A']) * 2
				} else if b <= c && c <= m {
					lans += vals[b] - vals[c]
				} else if b <= m && m <= c {
					lans += vals[b] + vals[c]
					lans += (prefix[m - 'A'] - prefix[c - 'A']) * 2
				} else {
					lans += -vals[b] + vals[c]
					lans += (prefix[b - 'A'] - prefix[c - 'A']) * 2
				}

				if lans > ans {

					ans = lans
					ansI = i
					ansC = c
				}
			}

			for j := b - 'A' + 1; j < 5; j++ {
				prefix[j] += vals[b]
			}
		}

		Fprintln(out, ans, ansI, ansC - 'A')
	}
}

func main() {
	sol(os.Stdin, os.Stdout)
}

func maxr(a, b rune) rune {
	if a > b {
		return a
	} else {
		return b
	}
}

func maxi(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
