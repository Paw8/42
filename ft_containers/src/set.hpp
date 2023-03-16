/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:31:26 by pcordeir          #+#    #+#             */
/*   Updated: 2023/03/06 13:35:04 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bidirectional_iterator.hpp"
#include "redblacktree.hpp"
#include "utils.hpp"
#include "reverse_iterator.hpp"

namespace ft {

    template <class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key> >
    class set {
        public:
            typedef Key                                                             value_type;
            typedef Compare                                                         key_compare;
            typedef Compare                                                         value_compare;
            typedef Alloc                                                           allocator_type;
            typedef typename allocator_type::size_type                              size_type;
            typedef typename allocator_type::difference_type                        difference_type;
            typedef typename allocator_type::reference                              reference;
            typedef typename allocator_type::const_reference                        const_reference;
            typedef typename allocator_type::pointer                                pointer;
            typedef typename allocator_type::const_pointer                          const_pointer;
            typedef bidirectional_iterator<const value_type, rb_node<value_type> >  iterator;
            typedef bidirectional_iterator<const value_type, rb_node<value_type> >  const_iterator;
            typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                            const_reverse_iterator;
            typedef redblacktree<value_type, value_compare, allocator_type>         tree_type;

            set() : tree_(value_compare(), allocator_type()) {}

            explicit set(const Compare& comp, const Alloc& alloc = Alloc()) : tree_(comp, alloc) {}

            template <class InputIt>
            set(InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : tree_(comp, alloc) {
                insert(first, last);
            }

            set(const set& other) : tree_(other.tree_) {}

            ~set() {}

            set& operator=(set other) {
                if (*this != other) tree_.swap(other.tree_);
                return *this;
            }

            allocator_type get_allocator() const { return tree_.get_allocator(); }

            iterator begin() { return iterator(tree_.get_first()); }
            const_iterator begin() const { return const_iterator(tree_.get_first()); }
            iterator end() { return iterator(tree_.get_end()); }
            const_iterator end() const { return const_iterator(tree_.get_end()); }
            reverse_iterator rbegin() { return reverse_iterator(tree_.get_end()); }
            const_reverse_iterator rbegin() const { return reverse_iterator(tree_.get_end()); }
            reverse_iterator rend() { return reverse_iterator(tree_.get_first()); }
            const_reverse_iterator rend() const { return reverse_iterator(tree_.get_first()); }

            bool empty() const { return (size() == 0); }
            size_type size() const { return tree_.size(); }
            size_type max_size() const { return tree_.max_size(); }

            void clear() { tree_.clear(); }

            ft::pair<iterator, bool> insert(const value_type& value) {
                ft::pair<typename tree_type::node_type*, bool> tmp = tree_.insert(value);
                return ft::pair<iterator, bool>(iterator(tmp.first), tmp.second);
            }

            iterator insert(iterator pos, const value_type& value) {
                (void)pos;
                return iterator(tree_.insert(value).first);
            }

            template <class InputIt>
            void insert(InputIt first, InputIt last) {
                while (first != last) tree_.insert(*(first++));
            }

            void erase(iterator pos) { tree_.erase(*pos); }

            void erase(iterator first, iterator last) {
                while (first != last) tree_.erase(*(first++));
            }

            size_type erase(const Key& key) {
                bool erased = tree_.erase(key);
                return erased;
            }

            void swap(set& other) { tree_.swap(other.tree_); }

            size_type count(const Key& key) const {
                (void)key;
                iterator it1(tree_.find(key));
                iterator it2(tree_.get_end());
                if (it1 == it2) return 0;
                return 1;
            }

            iterator find(const Key& key) { return iterator(tree_.find(key)); }

            const_iterator find(const Key& key) const {
                return const_iterator(tree_.find(key));
            }

            ft::pair<iterator, iterator> equal_range(const Key& key) {
                return ft::make_pair(lower_bound(key), upper_bound(key));
            }
            ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const {
                return ft::make_pair(lower_bound(key), upper_bound(key));
            }
            iterator lower_bound(const Key& key) {
                return iterator(tree_.lower_bound(key));
            }
            const_iterator lower_bound(const Key& key) const {
                return const_iterator(tree_.lower_bound(key));
            }
            iterator upper_bound(const Key& key) {
                return iterator(tree_.upper_bound(key));
            }
            const_iterator upper_bound(const Key& key) const {
                return const_iterator(tree_.upper_bound(key));
            }

            key_compare key_comp() const { return key_compare(); }

            value_compare value_comp() const { return value_compare(key_compare()); }

        private:
            tree_type tree_;
    };
    
    //	end of class definition
    
    template <class Key, class Compare, class Alloc>
    bool operator==(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <class Key, class Compare, class Alloc>
    bool operator!=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
        return !(lhs == rhs);
    }

    template <class Key, class Compare, class Alloc>
    bool operator<(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class Key, class Compare, class Alloc>
    bool operator>(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
      return !(lhs < rhs || lhs == rhs);
    }

    template <class Key, class Compare, class Alloc>
    bool operator<=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
      return !(lhs > rhs);
    }

    template <class Key, class Compare, class Alloc>
    bool operator>=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
      return !(lhs < rhs);
    }

    template <class Key, class Compare, class Alloc>
    void swap(ft::set<Key, Compare, Alloc>& lhs, ft::set<Key, Compare, Alloc>& rhs) {
        lhs.swap(rhs);
    }

}	// end of namespace definition
