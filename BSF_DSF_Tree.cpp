/*
  Deep Searh First
  Broad Search First for binary trees

*/
	struct Node {
		int val=0;
		Node *left=nullptr;
		Node *right=nullptr;
	};

	void _printDSF(Node *hd) {

		if (hd->left)
			_printDSF(hd->left);

		cout << "[" << hd->val << "] ";

		if (hd->right)
			_printDSF(hd->right);
	}

	void _printBSF(Node *hd) {

		list<Node*> q;
		q.push_front(hd);

		while (q.size() > 0) {
			Node *next = q.back();

			cout << "[" << next->val << "] ";
			if(next->left)
				q.push_front(next->left);
			
			if(next->right)
				q.push_front(next->right);
			
			q.pop_back();
		}
	}
	
	