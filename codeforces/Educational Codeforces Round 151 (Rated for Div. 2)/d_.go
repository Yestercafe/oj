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
		var n int
		Fscan(in, &n)
		arr := make([]int, n)
		for i := range arr {
			Fscan(in, &arr[i])
		}

		var lst []int
		con := 0
		for _, a := range arr {
			if con == 0 || con / abs(con) == a / abs(a) {
				con += a
				continue
			}
			lst = append(lst, con)
			con = a
		}
		if con != 0 {
			lst = append(lst, con)
		}

		n = len(lst)
		suf := make([]int, n + 1)
		for i := n - 1; i >= 0; i-- {
			if lst[i] > 0 {
				if i + 1 < n {
					suf[i] = suf[i + 1] + max(0, lst[i] + lst[i + 1])
				} else {
					suf[i] = suf[i + 1] + lst[i]
				}
			} else {
				suf[i] = suf[i + 1]
			}
		}

		ans := math.MinInt
		k := 0
		pref := 0
		for i, a := range lst {
			if ans < pref + suf[i + 1] {
				k = pref
				ans = pref + suf[i + 1]
			}
			pref += a
		}

		Fprintln(out, k)
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

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
