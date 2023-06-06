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
		var n, k, q int
		Fscan(in, &n, &k, &q)
		cnt, ans := 0, 0
		var ct int

		// temp <= q
		for i := 0; i < n; i++ {
			Fscan(in, &ct)
			if ct <= q {
				cnt++
			} else {
				least := cnt - k + 1
				if least > 0 {
					if least % 2 == 0 {
						ans += least / 2 * (least + 1)
					} else {
						ans += (least + 1) / 2 * least
					}
				}
				cnt = 0
			}
		}
		least := cnt - k + 1
		if least > 0 {
			if least % 2 == 0 {
				ans += least / 2 * (least + 1)
			} else {
				ans += (least + 1) / 2 * least
			}
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
