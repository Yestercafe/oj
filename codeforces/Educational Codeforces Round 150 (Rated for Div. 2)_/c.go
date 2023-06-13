package main

import (
	. "fmt"
	"os"
	"io"
	"bufio"
	"math"
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
		
		n := len(s)
		f := make([][][]int, n + 1)
		for i := range f {
			f[i] = make([][]int, 5)
			for j := range f[i] {
				f[i][j] = make([]int, 2)
				f[i][j][0] = math.MinInt / 4
				f[i][j][1] = math.MinInt / 4
			}
		}
		f[n][0][0] = 0

		vals := []int{1, 10, 100, 1000, 10000}

		for i := n - 1; i >= 0; i-- {
			for j := range f[i] {
				for k := range f[i][j] {
					for o := range f[i] {
						v := f[i + 1][j][k]
						if o < j {
							v -= vals[o]
						} else {
							v += vals[o]
						}
						nj := maxi(o, j)
						nk := k
						if int(s[i] - 'A') != o { nk++ }
						if nk > 1 { continue }
						f[i][nj][nk] = maxi(f[i][nj][nk], v)
					}
				}
			}
		}

		ans := math.MinInt
		for j := range f[0] {
			ans = maxi(ans, f[0][j][0])
			ans = maxi(ans, f[0][j][1])
		}

		Fprintln(out, ans)
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
