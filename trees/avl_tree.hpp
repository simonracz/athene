#ifndef avl_tree_hpp
#define avl_tree_hpp

#include <cstddef>
#include <string>
#include <sstream>
#include <vector>
#include <random>

namespace athene {
	
template<class T>
class naive_bs_tree {
public:
	struct Node {
		Node() {}
		Node(const T& val) : val{val} {}
		T val{};
		Node* left{nullptr};
		Node* right{nullptr};
		Node* parent{nullptr};
	};

	typedef typename naive_bs_tree<T>::Node* iterator;
	
	naive_bs_tree() {}
	~naive_bs_tree();
	
	iterator insert(const T& val);
	iterator find(const T& val);
	bool erase(const T& val);
	T& min();
	T& max();
	
	std::size_t size();
	
	iterator firstNode();
	iterator lastNode();
	
	iterator next(iterator node);
	iterator prev(iterator node);
	
	void clear();
	
	std::string print();
	std::string print_backwards();
	void read(std::string input);
	
	iterator get_root() {return root;}
	
private:
	std::size_t mSize{0};
	iterator root{nullptr};
	bool has_left(iterator node);
	bool has_right(iterator node);
	bool is_left_of_parent(iterator node);
	bool is_right_of_parent(iterator node);
	
	iterator min_impl(iterator node);
	iterator max_impl(iterator node);
	
	iterator find_node(const T& val);
	iterator find_node_impl(iterator node, const T& val);
};

template<class T>
std::size_t	naive_bs_tree<T>::size()
{
	return mSize;
}
	
template<class T>
naive_bs_tree<T>::~naive_bs_tree()
{
	clear();
}
	
template<class T>
void naive_bs_tree<T>::clear()
{
	if (mSize == 0) return;
	std::size_t tmp = mSize;
	for (std::size_t s=0; s<tmp; ++s) {
		erase(min());
	}
}
	
template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::find(const T& val)
{
	iterator tmp=find_node(val);
	if (tmp->val!=val) return nullptr;
	return tmp;
}

template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::find_node(const T& val)
{
	return find_node_impl(root, val);
}

template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::find_node_impl(iterator node, const T& val)
{
	if (node->val == val) return node;
	
	if (node->val > val) {
		if (has_left(node)) {
			return find_node_impl(node->left, val);
		} else {
			return node;
		}
	}
	
	if (has_right(node)) {
		return find_node_impl(node->right, val);
	}
	return node;
}
template<class T>
bool naive_bs_tree<T>::has_left(iterator node)
{
	if (node->left == nullptr) return false;
	
	return true;
}
template<class T>
bool naive_bs_tree<T>::has_right(iterator node)
{
	if (node->right == nullptr) return false;
	
	return true;
}
template<class T>
bool naive_bs_tree<T>::is_left_of_parent(iterator node)
{
	iterator p = node->parent;
	if (p == nullptr) return false;
	if (p->left == node) return true;
	return false;
}
template<class T>
bool naive_bs_tree<T>::is_right_of_parent(iterator node)
{
	iterator p = node->parent;
	if (p == nullptr) return false;
	if (p->right == node) return true;
	return false;
}
template<class T>
T& naive_bs_tree<T>::min()
{
	return min_impl(root)->val;
}
template<class T>
T& naive_bs_tree<T>::max()
{
	return max_impl(root)->val;
}
template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::min_impl(iterator node)
{
	while(has_left(node)) {
		node = node->left;
	}
	return node;
}
template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::max_impl(iterator node)
{
	while(has_right(node)) {
		node = node->right;
	}
	return node;
}
template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::firstNode()
{
	return min_impl(root);
}
template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::lastNode()
{
	return max_impl(root);
}
template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::insert(const T& val)
{
	if (mSize==0) {
		root = new Node(val);
		++mSize;
		return root;
	}
	
	Node* node = find_node(val);
	if (node->val == val) return node;

	Node* newNode = new Node(val);
	newNode->parent = node;
	if (node->val < val) {
		node->right = newNode;
	} else {
		node->left = newNode;
	}
	
	++mSize;
	return newNode;
}
template<class T>
bool naive_bs_tree<T>::erase(const T& val)
{
	if (mSize == 0) return false;
	iterator node = find_node(val);
	if (node->val != val) return false;
	iterator p = node->parent;
	
	if (!node->left && !node->right) {
		if (!p) {
			root = nullptr;
		} else {
			if (is_left_of_parent(node)) {
				p->left = nullptr;
			} else {
				p->right = nullptr;
			}
		}
		delete node;
		--mSize;
		return true;
	}
	
	if (!node->left) {
		if (!p) {
			root = node->right;
			root->parent = nullptr;
		} else {
			node->right->parent = p;
			if (is_left_of_parent(node)) {
				p->left = node->right;
			} else {
				p->right = node->right;
			}
		}
		delete node;
		--mSize;
		return true;
	}
	
	if (!node->right) {
		if (!p) {
			root = node->left;
			root->parent = nullptr;
		} else {
			node->left->parent = p;
			if (is_left_of_parent(node)) {
				p->left = node->left;
			} else {
				p->right = node->left;
			}
		}
		delete node;
		--mSize;
		return true;
	}
	
	iterator m = max_impl(node->left);
	iterator mp = m->parent;
	iterator mLeft = m->left;
	if (!p) {
		root = m;
		m->parent = nullptr;
	} else {
		m->parent = p;
		if (is_left_of_parent(node)) {
			node->parent->left = m;
		} else {
			node->parent->right = m;
		}
	}
	m->right = node->right;
	m->right->parent = m;
	if (m != node->left) {
		m->left = node->left;
		m->left->parent = m;
		mp->right = mLeft;
		if (mLeft) mLeft->parent = mp;
	}
	
	delete node;
	--mSize;
	return true;
}
template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::next(iterator node)
{
	if (node->right) return min_impl(node->right);

	while (is_right_of_parent(node)) {
		node = node->parent;
	}
	
	return node->parent;
}
template<class T>
typename naive_bs_tree<T>::iterator
naive_bs_tree<T>::prev(iterator node)
{
	if (node->left) return max_impl(node->left);
	
	while (is_left_of_parent(node)) {
		node = node->parent;
	}
	
	return node->parent;
}
template<class T>
std::string naive_bs_tree<T>::print()
{
	if (mSize == 0) return "{0}";
	
	std::stringstream str;
	str << "{" << mSize;
	iterator node = firstNode();
	while (node!=nullptr) {
		str << "," << node->val;
		node = next(node);
	}
	str << "}";
	return str.str();
}
template<class T>
std::string naive_bs_tree<T>::print_backwards()
{
	if (mSize == 0) return "{0}";
	
	std::stringstream str;
	str << "{" << mSize;
	iterator node = lastNode();
	while (node!=nullptr) {
		str << "," << node->val;
		node = prev(node);
	}
	str << "}";
	return str.str();
}
template<class T>
void naive_bs_tree<T>::read(std::string input)
{
	clear();
	
	std::stringstream ss{input};
	char c;
	ss >> c;
	assert(c == '{');
	
	std::size_t s;
	ss >> s;
	if (s==0) return;
	
	std::vector<T> vec;
	vec.reserve(s);
	
	T tmp;
	
	for (std::size_t i=0; i<s; ++i) {
		ss >> c;
		ss >> tmp;
		vec.push_back(tmp);
	}
	
	ss >> c;
	assert(c == '}');
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 m(seed);
	
	//poor man's rebalancer ;)
	std::shuffle(vec.begin(), vec.end(), m);
	for (auto& it : vec) {
		insert(it);
	}
}
	
}

/*
template<class T>
class avl_tree {
	friend class simple_iterator;
	sts::size_t size{0};
	struct Node {
		Node() {}
		Node(T val) : val{val} {}
		T val{};
		Node* left{nullptr};
		Node* right{nullptr};
		Node* parent{nullptr};
	};
	Node* root{nullptr};
public:
	struct simple_iterator {
	private:
		friend class avl_tree;
		Node* node;
	public:
		simple_iterator(Node* node) : node{node} {}
		simple_iterator(const simple_iterator& mit) : node{mit.node} {}
		
		simple_iterator& operator++();
		simple_iterator operator++(int) {simple_iterator tmp(*this); operator++(); return tmp;}
		simple_iterator& operator--();
		simple_iterator operator--(int) {simple_iterator tmp(*this); operator--(); return tmp;}
		bool operator==(const simple_iterator& rhs) {return node==rhs.node;}
		bool operator!=(const simple_iterator& rhs) {return node!=rhs.node;}
		T& operator*() {return node->val;}
	};
	avl_tree() {}
	
	void insert(const T& val);
	pair<simple_iterator, bool> find(const T& val);
	void erase(const T& val);
	simple_iterator begin();
	simple_iterator end();
	T& min() {return *begin(); }
	T& max() {return *end(); }
	
	
};
*/

/*

template<class T>
class avl_tree {
public:
	struct iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
		
	private:
		friend class avl_tree;
		iterator() {}
		iterator(Node* node) : node{node} {}
		Node* node{nullptr};
	};
	
	iterator begin();
	iterator end();
	
	
private:
	friend class iterator;
	struct Node {
		Node() {}
		Node(T val) : val{val} {}
		T val{};
		Node* left{nullptr};
		Node* right{nullptr};
		Node* parent{nullptr};
	};
	Node* root{nullptr};
	std::size_t size{0};
};

template<typename K, typename D>
class avl_map {
public:
	using value_type = std::pair<const K, D>;
	
	bool insert(const value_type& val);
	void erase(const K& key);
	bool find(const K& key, value_type& ret);
	
	K min();
	K max();
	
	
	
};

template<typename K>
class avl_set {
public:
	void insert(const K& key);
	void erase(const K& key);
	bool find(const K& key);
	
	K min();
	K max();
	
	
};
 */


#endif