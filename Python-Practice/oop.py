class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
def create_ll(arr):
    if not arr:
        return None
    
    head = ListNode(arr[0])
    cur = head
    
    for val in arr[1:]:
        cur.next = ListNode(val)
        cur = cur.next
    return head
    
def rev(head):

    dummy = None
    
    while head:
        next = head.next
        head.next = dummy
        dummy = head
        head = next
    
    return dummy
    
def recrev(cur, prev=None):
    if cur is None:
        return prev
    
    nxt = cur.next
    cur.next = prev
    prev = cur
    
    cur = nxt
    return recrev(cur,prev)

def printll(head):
    temp = head
    while temp:
        print(temp.val)
        temp = temp.next
        

def tail_rec(head):
    if not head or not head.next:
        return head
    
    new_head = tail_rec(head.next)
    
    head.next.next = head
    head.next = None

    return new_head
    
    
def rec_rev_k(head, k):
    c = 0
    
    temp = head
    while temp and c < k:
        c += 1
        temp = temp.next
    
    if c < k: 
        return head
    
    prev, cur = None, head
    
    for _ in range(k):
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    
    head.next = rec_rev_k(cur, k)
    
    return prev
    
    
def iter_k(head,k):
    
    dummy = ListNode(0,head)
    group_bef = dummy
    

    while True:
        c = 0
        temp = group_bef
        while c<k and temp.next:
            c+=1
            temp = temp.next
            
        if c < k:
            break
            
        cur, prev = group_bef.next, None
        for _ in range(k):
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
            
        
        next_bef = group_bef.next
        group_bef.next = prev
        next_bef.next = cur
        group_bef = next_bef
     
    return dummy.next


if __name__ == "__main__":
    arr = [1,2,3,4,5]
    
    head = create_ll(arr)
    printll(head)
    

    head = iter_k(head,2)
    printll(head)
