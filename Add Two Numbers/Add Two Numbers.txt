class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result;
		ListNode *r1;
		ListNode *rnew;
		ListNode *p = l1, *q = l2;
		vector<int> a;
		vector<int> b;
		for (; p != NULL; p = p->next) {
			a.push_back(p->val);
		}
		for (; q != NULL; q = q->next) {
			b.push_back(q->val);
		}
		if (a.back() == 0)
			return l2;
		if (b.back() == 0)
			return l1;
		r1 = (ListNode*)malloc(sizeof(ListNode));
		result = r1;
		int cont = 0;
		int c = 0;
		if (a.size() <= b.size()) {
			for (unsigned int i = 0; i < a.size(); i++) {
				rnew = (ListNode*)malloc(sizeof(ListNode));
				c = a[i] + b[i] + cont;
				//cout << c << endl;
				if (c >= 10) {
					rnew->val = c % 10;
					//cout << rnew->val << endl;
					r1->next = rnew;
					r1 = rnew;
					cont = 1;
				}
				else {
					rnew->val = c;
					//cout << rnew->val << endl;
					r1->next = rnew;
					r1 = rnew;
					cont = 0;
				}
			}
			if (a.size() == b.size()) {
				if (cont == 1) {
					rnew = (ListNode*)malloc(sizeof(ListNode));
					rnew->val = 1;
					//cout << rnew->val << endl;
					r1->next = rnew;
					r1 = rnew;
					r1->next = NULL;
					return result->next;
				}
				else {
					r1->next = NULL;
					return result->next;
				}	
			}
			else {
				for (unsigned int i = a.size(); i < b.size(); i++){
					rnew = (ListNode*)malloc(sizeof(ListNode));
					c = b[i] + cont;
					if (c == 10)
						rnew->val = 0;
					else {
						rnew->val = c;
						cont = 0;
					}
					//cout << rnew->val << endl;
					r1->next = rnew;
					r1 = rnew;
				}
				if (cont == 1) {
					rnew = (ListNode*)malloc(sizeof(ListNode));
					rnew->val = 1;
					//cout << rnew->val << endl;
					r1->next = rnew;
					r1 = rnew;
					r1->next = NULL;
					return result->next;
				}
			}
		}
		else {
			for (unsigned int i = 0; i < b.size(); i++){
				rnew = (ListNode*)malloc(sizeof(ListNode));
				c = a[i] + b[i] + cont;
				//cout << c << endl;
				if (c >= 10) {
					rnew->val = c % 10;
					r1->next = rnew;
					r1 = rnew;
					cont = 1;
				}
				else {
					rnew->val = c;
					r1->next = rnew;
					r1 = rnew;
					cont = 0;
				}
			}
			for (unsigned int i = b.size(); i < a.size(); i++){
				rnew = (ListNode*)malloc(sizeof(ListNode));
				c = a[i] + cont;
				if (c == 10)
					rnew->val = 0;
				else {
					rnew->val = c;
					cont = 0;
				}
				//cout << rnew->val << endl;
				r1->next = rnew;
				r1 = rnew;
			}
			if (cont == 1) {
				rnew = (ListNode*)malloc(sizeof(ListNode));
				rnew->val = 1;
				//cout << rnew->val << endl;
				r1->next = rnew;
				r1 = rnew;
				r1->next = NULL;
				return result->next;
			}
		}
		r1->next = NULL;	
		return result->next;
	}
};