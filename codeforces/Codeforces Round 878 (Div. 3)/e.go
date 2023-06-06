package main

import (
	. "fmt"
	"os"
	"io"
	"bufio"
)

type block struct {
	time int
	idx int
	stat bool    // eq
}

func newBlock(time, idx int, stat bool) block {
	return block {
		time: time,
		idx: idx,
		stat: stat,
	}
}

func sol(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T int
	for Fscan(in, &T); T > 0; T-- {
		var s1_, s2_ string
		Fscan(in, &s1_, &s2_)
		s1, s2 := []rune(s1_), []rune(s2_)

		neq := 0
		for i := range s1 {
			if s1[i] != s2[i] {
				neq++
			}
		}

		var t, q int
		Fscan(in, &t, &q)

		qe := []block{}
		blocked := make([]bool, len(s1))
		for tick := 0; tick < q; tick++ {
			if len(qe) > 0 {
				fr := &qe[0]
				if fr.time == tick {
					// Fprintln(out, tick, fr.time, fr.idx, fr.stat)
					if s1[fr.idx] != s2[fr.idx] {
						neq++
					}
					blocked[fr.idx] = false
					qe = qe[1:]
				}
			}

			ins := 0
			Fscan(in, &ins)

			change := func (ori bool, idx int) {
				if ori == (s1[idx] == s2[idx]) {
					return
				} else if ori {
					neq++
				} else {
					neq--
				}
			}

			if ins == 1 {
				idx := 0
				Fscan(in, &idx)
				idx--

				qe = append(qe, newBlock(tick + t, idx, s1[idx] == s2[idx]))
				blocked[idx] = true

				if s1[idx] != s2[idx] {
					neq--
				}
			} else if ins == 2 {
				w1, i1, w2, i2 := 0, 0, 0, 0
				Fscan(in, &w1, &i1, &w2, &i2)
				i1--
				i2--

				b1, b2 := s1[i1] == s2[i1], s1[i2] == s2[i2]
				if w1 == 1 && w2 == 1 {
					s1[i1], s1[i2] = s1[i2], s1[i1]
				} else if w1 == 2 && w2 == 2 {
					s2[i1], s2[i2] = s2[i2], s2[i1]
				} else {
					if w1 > w2 {         // w1 = 2, w2 = 1
						i1, i2 = i2, i1
						b1, b2 = b2, b1
					}
					s1[i1], s2[i2] = s2[i2], s1[i1]
				}

				if !blocked[i1] {
					change(b1, i1)
				}
				if i1 != i2 && !blocked[i2] {
					change(b2, i2)
				}

			} else {   // == 3
				if neq == 0 {
					Fprintln(out, "YES")
				} else {
					Fprintln(out, "NO")
				}
			}
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
