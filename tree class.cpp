
class tree {
public:

	// data

	ll value, count = 1;
	tree* right;
	tree* left;
	tree* prev;

	// Functions
	/*----------------------------------
		   Add Function
	-------------------------------------*/
	void addn(ll num, tree* node) {
		//if num==node
		if (node->value == num)node->count++;
		// if num < node
		else if ((node->value) < num) {
			// if the node is at the end
			if (node->right == NULL) {
				tree* temp;
				temp = new tree;
				node->right = temp;
				temp->right = NULL;
				temp->left = NULL;
				temp->prev = node;
			}

			// if the node is on the mid

			else {
				addn(num, node->right);
			}
		}
		//if num > node
		else if ((node->value) > num) {
			// if the node is at the end
			if (node->left == NULL) {
				tree* temp;
				temp = new tree;
				node->left = temp;
				temp->right = NULL;
				temp->left = NULL;
				temp->prev = node;
			}
			// if the node is on the mid
			else {
				addn(num, node->left);
			}
		}
	}
	/*----------------------------------
		   Suc Function
	-------------------------------------*/
	tree* Suc(tree* node) {
		// if right is not empty
		if (node->right != NULL) {
			return minn(node->right);
		}
		// if right is empty
		else {

			tree* temp = node->prev;
			tree* s = node;

			while (temp->right == node && temp->prev != NULL) {
				s = temp;
				tree* temp = temp->prev;
			}

			if (temp->prev == NULL)return NULL;
			else return temp->prev;

		}
	}
	/*----------------------------------
		   Search Function
	-------------------------------------*/
	tree* b_search(ll num, tree * node) {
		if (node->value == num)return node;
		else if ((node->value) < num) {
			if (node->right == NULL) {
				return NULL;
			}
			else {
				b_search(num, node->right);
			}
		}
		else if ((node->value) > num) {
			if (node->left == NULL) {
				return NULL;
			}
			else {
				b_search(num, node->left);
			}
		}
	}
	/*----------------------------------
		   Remove Function
	-------------------------------------*/
	void deln(tree * node) {



	}
	/*----------------------------------
		   Min Function
	-------------------------------------*/
	tree* minn(tree * node) {

		if (node->left != NULL)minn(node->left);

		else return node;

	}

	/*----------------------------------
		   Max Function
	-------------------------------------*/

	tree* maxn(tree * node) {

		if (node->right != NULL)maxn(node->right);

		else return node;
	}
};

