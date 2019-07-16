// 24. Swap Nodes in Pairs
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode curr = head;
        ListNode next;
        ListNode prev = null;
        while ((curr != null) && (curr.next != null)) {
            next = curr.next;
            curr.next = next.next;
            next.next = curr;
            if (prev != null) {
                prev.next = next;   
            } else {
                head = next;
            }
            prev = curr;
            curr = curr.next;
        }
        return head;
    }
}
