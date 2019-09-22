//1199. Minimum Time to Build Blocks
/*
You are given a list of blocks, where blocks[i] = t means that the i-th block needs t units of time to be built. A block can only be built by exactly one worker.

A worker can either split into two workers (number of workers increases by one) or build a block then go home. Both decisions cost some time.

The time cost of spliting one worker into two workers is given as an integer split. Note that if two workers split at the same time, they split in parallel so the cost would be split.

Output the minimum time needed to build all blocks.

Initially, there is only one worker.
*/
type WChain struct {
	cost int    
	index int 
}

type WPQ []*WChain

func (pq WPQ) Len() int { return len(pq) }

func (pq WPQ) Less(i, j int) bool {
	return pq[i].cost < pq[j].cost
}

func (pq WPQ) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *WPQ) Push(x interface{}) {
	n := len(*pq)
	chain := x.(*WChain)
	chain.index = n
	*pq = append(*pq, chain)
}

func (pq *WPQ) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func minBuildTime(blocks []int, split int) int {
    pq := make(WPQ, len(blocks))

	for i, block_cost := range blocks {
		item := &WChain{cost: block_cost}
		pq[i] = item
	}

	heap.Init(&pq)

	for pq.Len() > 1 {
		chain0 := heap.Pop(&pq).(*WChain)
		chain1 := heap.Pop(&pq).(*WChain)

		merged_chain := &WChain{cost: split + max(chain0.cost, chain1.cost)}
		heap.Push(&pq, merged_chain)
	}

	final_chain := heap.Pop(&pq).(*WChain)
	return final_chain.cost
}
