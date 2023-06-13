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

		minn := math.MaxInt
		seq := []int{-1}
		back := func () int {
			return seq[len(seq) - 1]
		}
		cntAes := 0
		push := func (a int) {
			if back() > a {
				cntAes++
			}
			seq = append(seq, a)
			Fprint(out, "1")
		}
		notPush := func () {
			Fprint(out, "0")
		}

		for _, v := range arr {
			// Fprint(out, v, back(), cntAes, minn, "\n      ")
			if cntAes >= 1 && back() > v {
				notPush()
				continue
			}
			if cntAes == 0 && back() <= v {
				push(v)
				minn = min(minn, v)
			} else if cntAes == 0 && back() > v {
				if v <= minn {
					push(v)
				} else {
					notPush()
				}
			} else if cntAes == 1 && back() <= v && v <= minn {
				push(v)
			} else {
				notPush()
			}
		}
		Fprintln(out)
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
