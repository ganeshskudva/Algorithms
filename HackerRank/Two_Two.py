import sys
from collections import deque


class Node(object):
    def __init__(self, ch, transitions=None, results=0, fail=None):
        self.ch = ch
        self.transitions = transitions if transitions else {}
        self.results = 0
        self.fail = fail

    def __repr__(self):
        return 'Node(%r, [...], %r, ...)' % (self.ch, self.results)


def init_tree():
    keywords = []
    p = 1
    while p <= 2 ** 800:
        keywords.append(str(p))
        p *= 2

    root = Node(ch=None, fail=None)
    root.fail = root

    for keyword in keywords:
        current_node = root
        for char in keyword:
            new_node = None
            for ch, transition in current_node.transitions.items():
                if ch == char:
                    new_node = transition
                    break

            if new_node is None:
                new_node = Node(ch=char)
                current_node.transitions[char] = new_node
                if current_node is root:
                    new_node.fail = root

            current_node = new_node
        current_node.results = 1

    queue = deque([root])

    while queue:
        current_node = queue.popleft()
        for node in current_node.transitions.values():
            queue.append(node)
            fail_state_node = current_node.fail
            while not fail_state_node.transitions.get(node.ch) and fail_state_node is not root:
                fail_state_node = fail_state_node.fail

            fail = fail_state_node.transitions.get(node.ch, root)
            node.fail = fail if fail is not node else root
            node.results += node.fail.results

    return root


def solve(tree, text):
    result = 0
    current_node = tree
    for c in text:
        while True:
            transition = current_node.transitions.get(c)
            if transition is not None:
                current_node = transition
                break
            if current_node is tree:
                break
            current_node = current_node.fail

        result += current_node.results

    return result


if __name__ == '__main__':
    tree = init_tree()
    T = int(raw_input())
    for t in range(T):
        print solve(tree, sys.stdin.readline().strip())
