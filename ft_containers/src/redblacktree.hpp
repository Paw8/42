/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redblacktree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:18:40 by pcordeir          #+#    #+#             */
/*   Updated: 2023/03/06 13:24:24 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pair.hpp"
#include "utils.hpp"

namespace ft {

    enum node_color { RED, BLACK };

    template <class U>
    class rb_node {
        public:
            rb_node() : data(U()), parent(NULL), left_child(NULL), right_child(NULL), color(RED), is_null_node(true) {}
            rb_node(const U& value) : data(U(value)), parent(NULL), left_child(NULL), right_child(NULL), color(RED), is_null_node(false) {}

            U data;
            rb_node *parent;
            rb_node *left_child;
            rb_node *right_child;
            node_color color;
            bool is_null_node;
    };

    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class redblacktree {
        public:
            typedef Compare                                                 key_compare;
            typedef T                                                       value_type;
            typedef rb_node<value_type>                                     node_type;
            typedef typename Alloc::template rebind<node_type>::other       allocator_type;
            typedef typename allocator_type::size_type                      size_type;
            typedef typename allocator_type::difference_type                difference_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;

            redblacktree(key_compare comparator, const Alloc& alloc = Alloc()) : allocator_(alloc), cmp_(comparator), size_(0) {
                off_the_end_ = new_node_();
                off_the_end_->color = BLACK;
                off_the_end_->left_child = off_the_end_;
                off_the_end_->right_child = off_the_end_;
                root_ = off_the_end_;
                first_ = off_the_end_;
                last_ = off_the_end_;
                off_the_end_->parent = last_;
            }

            redblacktree(const redblacktree& other) : allocator_(allocator_type()), cmp_(other.cmp_), size_(other.size_) {
                off_the_end_ = new_node_();
                off_the_end_->color = BLACK;
                off_the_end_->left_child = off_the_end_;
                off_the_end_->right_child = off_the_end_;
                root_ = off_the_end_;
                first_ = off_the_end_;
                last_ = off_the_end_;
                if (other.root_->is_null_node) return;
                root_ = new_node_(other.root_->data, off_the_end_);
                root_->color = BLACK;
                root_->left_child = copy_subtree_(other.root_->left_child, root_);
                root_->right_child = copy_subtree_(other.root_->right_child, root_);
                pointer tmp = root_;
                while (!tmp->left_child->is_null_node) tmp = tmp->left_child;
                first_ = tmp;
                tmp = root_;
                while (!tmp->right_child->is_null_node) tmp = tmp->right_child;
                set_last_(tmp);
            }

            ~redblacktree() {
                clear();
                destroy_node_(off_the_end_);
            }

            redblacktree& operator=(redblacktree other) {
                swap(*this, other);
                return *this;
            }

            ft::pair<pointer, bool> insert(const value_type &value) {
                if (root_->is_null_node) {
                    root_ = new_node_(value, off_the_end_);
                    root_->color = BLACK;
                    first_ = root_;
                    set_last_(root_);
                    size_ = 1;
                    return ft::pair<pointer, bool>(root_, true);
                }

                pointer tmp = root_;
                pointer parent = off_the_end_;
                while (!tmp->is_null_node) {
                    parent = tmp;
                    if (key_is_less_(value, tmp->data))
                        tmp = tmp->left_child;
                    else if (key_is_greater_(value, tmp->data))
                        tmp = tmp->right_child;
                    else
                        return ft::pair<pointer, bool>(tmp, false);
                }

                // make new node
                tmp = new_node_(value, parent);
                ++size_;
                if (key_is_less_(value, parent->data))
                    parent->left_child = tmp;
                else
                    parent->right_child = tmp;

                // update member variables
                if (key_is_less_(tmp->data, first_->data))
                    first_ = tmp;
                else if (key_is_greater_(tmp->data, last_->data))
                    set_last_(tmp);
                rebalance_insert_(tmp);
                return ft::pair<pointer, bool>(tmp, true);
            }

            bool erase(value_type data) {
                pointer node = find(data);
                if (!node->is_null_node) {
                    delete_(node);
                    return true;
                } 
                else
                    return false;
            }

            size_type size() const { return size_; }

            void clear() {
                if (!root_->is_null_node) destroy_subtree_(root_);
                root_ = off_the_end_;
                first_ = off_the_end_;
                last_ = off_the_end_;
                size_ = 0;
            }

            void swap(redblacktree& other) {
                std::swap(root_, other.root_);
                std::swap(first_, other.first_);
                std::swap(last_, other.last_);
                std::swap(off_the_end_, other.off_the_end_);
                std::swap(allocator_, other.allocator_);
                std::swap(cmp_, other.cmp_);
                std::swap(size_, other.size_);
            }

            pointer find(const value_type& value) const {
                pointer current = root_;
                while (!current->is_null_node) {
                    if (key_is_equal_(value, current->data))
                        return current;
                    else if (key_is_less_(value, current->data))
                        current = current->left_child;
                    else
                        current = current->right_child;
                }
                return current;
            }

            pointer lower_bound(const value_type& value) const {
                pointer node = root_;
                pointer result = off_the_end_;
                while (!node->is_null_node) {
                    if (key_is_less_(node->data, value))
                        node = node->right_child;
                    else {
                        result = node;
                        node = node->left_child;
                    }
                }
                return result;
            }

            pointer upper_bound(const value_type& value) const {
                pointer node = root_;
                pointer result = off_the_end_;
                while (!node->is_null_node) {
                    if (key_is_greater_(node->data, value)) {
                        result = node;
                        node = node->left_child;
                    }
                    else
                        node = node->right_child;
                }
                return result;
            }

            pointer get_first() const { return first_; }

            pointer get_end() const { return off_the_end_; }

            size_type max_size() const { return allocator_.max_size(); }

            allocator_type get_allocator() const { return allocator_; }

        private:
            pointer root_;
            pointer first_;
            pointer last_;
            pointer off_the_end_;
            allocator_type allocator_;
            key_compare cmp_;
            size_type size_;

            void delete_(pointer node) {
                if (has_equal_or_fewer_than_one_children(node)) {
                    bool doubleblack = is_doubleblack_(node);
                    pointer parent = node->parent;
                    pointer replacement = remove_(node);
                    rebalance_delete_(replacement, parent, doubleblack);
                }
                else {
                    pointer predecessor = get_inorder_predecessor_(node);
                    std::swap(predecessor->data, node->data);
                    delete_(predecessor);
                }
            }

            void rebalance_delete_(pointer node, pointer parent, bool is_doubleblack) {
                if (node->color == RED)
                    node->color = BLACK;
                else if (node != root_ && is_doubleblack)
                    resolve_doubleblack_(node, parent);
            }

        void resolve_doubleblack_(pointer node, pointer parent) {
            pointer sibling;
            if (node == parent->left_child)
                sibling = parent->right_child;
            else
                sibling = parent->left_child;

            if (sibling->color == BLACK) {
                if (has_red_child_(sibling)) {
                    pointer red_child = get_outer_red_child_(sibling);
                    sibling->color = parent->color;
                    red_child->color = BLACK;
                    node->color = BLACK;
                    parent->color = BLACK;
                    restructure_(red_child, sibling, parent);
                }
                else {
                    sibling->color = RED;
                    if (parent->color == RED)
                    parent->color = BLACK;
                    else if (parent != root_)
                    resolve_doubleblack_(parent, parent->parent);
                }
            }
            else {
                sibling->color = BLACK;
                parent->color = RED;
                rotate_(node, parent, sibling);
                resolve_doubleblack_(node, parent);
            }
        }

        bool is_doubleblack_(pointer node) {
            return node->color == BLACK && node->left_child->color == BLACK &&
                node->right_child->color == BLACK;
        }

        bool has_red_child_(pointer node) {
            return node->left_child->color == RED || node->right_child->color == RED;
        }

        pointer get_outer_red_child_(pointer node) {
            if (node->left_child->color == RED) {
                if (node->right_child->color == RED && !is_left_child_(node))
                    return node->right_child;
                else
                    return node->left_child;
            }
            else
                return node->right_child;
        }

        pointer remove_(pointer node) {
            if (node == last_) set_last_(get_inorder_predecessor_(node));
            if (node == first_) first_ = get_inorder_successor_(node);
            pointer tmp = get_child_(node);
            if (node == root_) {
                root_ = tmp;
                tmp->parent = off_the_end_;
                destroy_node_(node);
                --size_;
                return tmp;
            }
            pointer parent = node->parent;
            if (is_left_child_(node))
                parent->left_child = tmp;
            else
                parent->right_child = tmp;
            if (!tmp->is_null_node) tmp->parent = parent;
            destroy_node_(node);
            --size_;
            return tmp;
        }

        pointer get_inorder_successor_(pointer node) {
            if (!node->right_child->is_null_node)
            return min_value_(node->right_child);
            else {
            pointer parent = node->parent;
            while (!parent->is_null_node && node == parent->right_child) {
                node = parent;
                parent = node->parent;
            }
            return parent;
            }
        }

        pointer get_inorder_predecessor_(pointer node) {
            if (!node->left_child->is_null_node)
                return max_value_(node->left_child);
            else {
                pointer parent = node->parent;
                while (!parent->is_null_node && node == parent->left_child) {
                    node = parent;
                    parent = node->parent;
                }
                return parent;
            }
        }

        pointer min_value_(pointer node) const {
            pointer current = node;
            while (!current->left_child->is_null_node) current = current->left_child;
            return current;
        }

        pointer max_value_(pointer node) const {
            pointer current = node;
            while (!current->right_child->is_null_node) current = current->right_child;
            return current;
        }

        pointer get_child_(pointer node) {
            if (!node->left_child->is_null_node)
                return node->left_child;
            else
                return node->right_child;
        }

        bool has_equal_or_fewer_than_one_children(pointer node) {
            return node->left_child->is_null_node || node->right_child->is_null_node;
        }

        void rebalance_insert_(pointer node) {
            if (node == root_) {
                node->color = BLACK;
                return;
            }
            pointer parent = node->parent;
            if (parent->color == RED) {
                pointer grandparent = parent->parent;
                if (insert_is_zick_zack_(node, parent)) {
                     pointer sibling = get_sibling_(node);
                    if (!sibling->is_null_node) {
                        rotate_(sibling, parent, node);
                        rebalance_insert_(sibling);
                        return;
                    }
                    else {
                        if (is_left_child_(node))
                            node->right_child = parent;
                        else
                            node->left_child = parent;
                        if (is_left_child_(parent))
                            parent->parent->left_child = node;
                        else
                            parent->parent->right_child = node;
                        node->parent = parent->parent;
                        parent->parent = node;
                        parent->left_child = off_the_end_;
                        parent->right_child = off_the_end_;
                        rebalance_insert_(parent);
                        return;
                    }
                }
                pointer uncle = get_sibling_(parent);
                if (uncle->color == BLACK) {
                    node->color = RED;
                    parent->color = BLACK;
                    grandparent->color = RED;
                    restructure_(node, parent, grandparent);
                }
                else {
                    parent->color = BLACK;
                    grandparent->color = RED;
                    uncle->color = BLACK;
                    rebalance_insert_(grandparent);
                }
            }
        }

        pointer get_sibling_(pointer node) {
            pointer parent = node->parent;
            if (node == parent->left_child) return parent->right_child;
            return parent->left_child;
        }

        void restructure_(pointer a, pointer b, pointer c) {
            pointer sibling = get_sibling_(a);
            if (!sibling->is_null_node) sibling->parent = c;
            if (is_left_child_(b))
                c->left_child = sibling;
            else
                c->right_child = sibling;
            if (c == root_) {
                root_ = b;
                b->parent = off_the_end_;
            }
            else if (c == c->parent->left_child) {
                c->parent->left_child = b;
                b->parent = c->parent;
            }
            else {
                c->parent->right_child = b;
                b->parent = c->parent;
            }
            make_children_(b, a, c);
        }

        void make_children_(pointer parent, pointer child1, pointer child2) {
            if (key_is_less_(child1->data, parent->data)) {
                parent->left_child = child1;
                parent->right_child = child2;
            }
            else {
                parent->left_child = child2;
                parent->right_child = child1;
            }
            child1->parent = parent;
            child2->parent = parent;
        }

        void rotate_(pointer node, pointer parent, pointer sibling) {
            if (parent == root_) {
                sibling->parent = off_the_end_;
                root_ = sibling;
            }
            else if (is_left_child_(parent)) {
                parent->parent->left_child = sibling;
                sibling->parent = parent->parent;
            }
            else {
                parent->parent->right_child = sibling;
                sibling->parent = parent->parent;
            }
            if (is_left_child_(node)) {
                parent->right_child = sibling->left_child;
                sibling->left_child->parent = parent;
                sibling->left_child = parent;
            }
            else {
                parent->left_child = sibling->right_child;
                sibling->right_child->parent = parent;
                sibling->right_child = parent;
            }
            parent->parent = sibling;
        }

        bool is_left_child_(pointer node) {
            if (node->parent->is_null_node) return false;
            return node == node->parent->left_child;
        }

        bool insert_is_zick_zack_(pointer node, pointer parent) {
            return (is_left_child_(node) != is_left_child_(parent));
        }

        pointer get_inward_child_(pointer node) {
            if (is_left_child_(node))
                return node->right_child;
            else
                return node->left_child;
        }

        void set_last_(pointer node) {
            last_ = node;
            off_the_end_->parent = last_;
        }

        pointer copy_subtree_(pointer node, pointer parent) {
            if (node->is_null_node) return off_the_end_;
            pointer tmp = new_node_(node->data, parent);
            tmp->color = node->color;
            tmp->parent = parent;
            tmp->left_child = copy_subtree_(node->left_child, tmp);
            tmp->right_child = copy_subtree_(node->right_child, tmp);
            return tmp;
        }

        void destroy_subtree_(pointer node) {
            if (node->is_null_node) return;
            destroy_subtree_(node->left_child);
            destroy_subtree_(node->right_child);
            destroy_node_(node);
            node = NULL;
        }

        bool key_is_less_(const value_type& element1, const value_type& element2) const {
            return cmp_(element1, element2);
        }

        bool key_is_greater_(const value_type& element1, const value_type& element2) const {
            return cmp_(element2, element1);
        }

        bool key_is_equal_(const value_type& element1, const value_type& element2) const {
            return !cmp_(element1, element2) && !cmp_(element2, element1);
        }

        pointer new_node_() {
            pointer tmp = allocator_.allocate(1);
            allocator_.construct(tmp, node_type());
            tmp->is_null_node = true;
            tmp->left_child = off_the_end_;
            tmp->right_child = off_the_end_;
            tmp->parent = off_the_end_;
            return tmp;
        }

        pointer new_node_(const value_type& value, pointer parent) {
            pointer tmp = allocator_.allocate(1);
            allocator_.construct(tmp, node_type(value));
            tmp->is_null_node = false;
            tmp->left_child = off_the_end_;
            tmp->right_child = off_the_end_;
            tmp->parent = parent;
            return tmp;
        }

        void destroy_node_(pointer node) {
            allocator_.destroy(node);
            allocator_.deallocate(node, 1);
        }
    };

    //	end of class definition

}	// end of namespace definition
