package main

import (
	. "fmt"
	"os"
	"io"
	"bufio"
	"sort"
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

		sort.Ints(arr)
		if arr[0] < 0 {
			Fprintln(out, arr[0])
		} else {
			Fprintln(out, arr[n - 1])
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
