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
		var ax, ay, bx, by, cx, cy int
		Fscan(in, &ax, &ay, &bx, &by, &cx, &cy)
		bx -= ax
		by -= ay
		cx -= ax
		cy -= ay
		// Fprintln(out, bx, by, cx, cy)

		ans := 0
		if bx != 0 && cx != 0 && bx / abs(bx) == cx / abs(cx) {
			ans += min(abs(bx), abs(cx))
		}
		if by != 0 && cy != 0 && by / abs(by) == cy / abs(cy) {
			ans += min(abs(by), abs(cy))
		}

		Fprintln(out, ans + 1)
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
