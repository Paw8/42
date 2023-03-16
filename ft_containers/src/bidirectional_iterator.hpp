/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:17:41 by pcordeir          #+#    #+#             */
/*   Updated: 2023/03/08 13:35:14 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <limits>
#include <memory>
#include <stdexcept>
#include "utils.hpp"
#include "iterator_traits.hpp"

namespace ft {

    template <class datatype, class node_type>
    class bidirectional_iterator {
        public:
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef datatype                        value_type;
            typedef datatype*                       pointer;
            typedef datatype&                       reference;
            typedef std::ptrdiff_t                  difference_type;

            bidirectional_iterator() : m_node(NULL) {}
            bidirectional_iterator(node_type *p) : m_node(p) {}
            bidirectional_iterator(const bidirectional_iterator &other) : m_node(other.m_node) {}
            ~bidirectional_iterator() {}

            bidirectional_iterator &operator=(const bidirectional_iterator &other) {
                this->m_node = other.m_node;
                return *this;
            }

            reference operator*() const { return m_node->data; }
            
            pointer operator->() const { return &(m_node->data); }

            bidirectional_iterator &operator++() {
                inorder_successor_();
                return *this;
            }
            bidirectional_iterator operator++(int) {
                bidirectional_iterator tmp(*this);
                inorder_successor_();
                return tmp;
            }
            
            bidirectional_iterator &operator--() {
                inorder_predecessor_();
                return *this;
            }
            bidirectional_iterator operator--(int) {
                bidirectional_iterator tmp(*this);
                inorder_predecessor_();
                return tmp;
            }

            pointer base() const { return &(m_node->data); }

            // Implicit conversion to const_iterator e.g. begin()
            operator bidirectional_iterator<const value_type, node_type>() const {
                return bidirectional_iterator<const value_type, node_type>(this->m_node);
            }

        private:
            node_type *m_node;

        private:
            void inorder_successor_() {
                if (!m_node->right_child->is_null_node)
                m_node = min_value_(m_node->right_child);
                else {
                node_type *parent = m_node->parent;
                while (!parent->is_null_node && m_node == parent->right_child) {
                    m_node = parent;
                    parent = m_node->parent;
                }
                m_node = parent;
                }
            }

            void inorder_predecessor_() {
                // The only null node is the off_the_end_ node which parent is last_
                if (m_node->is_null_node) {
                m_node = m_node->parent;
                return;
                }
                if (!m_node->left_child->is_null_node)
                m_node = max_value_(m_node->left_child);
                else {
                node_type *parent = m_node->parent;
                while (!parent->is_null_node && m_node == parent->left_child) {
                    m_node = parent;
                    parent = m_node->parent;
                }
                if (parent->is_null_node) {
                    m_node = NULL;
                    return;
                }
                m_node = parent;
                }
            }

            node_type *min_value_(node_type *node) const {
                node_type *current = node;
                while (!current->left_child->is_null_node) current = current->left_child;
                return current;
            }

            node_type *max_value_(node_type *node) const {
                node_type *current = node;
                while (!current->right_child->is_null_node) current = current->right_child;
                return current;
            }
    };

    // end of class definition

    // non-member function overloads

    template <class value_type, class node_type>
    bool operator==(const bidirectional_iterator<value_type, node_type> lhs, const bidirectional_iterator<value_type, node_type> rhs) {
        // std::cout << "equal non const" <<std::endl;
        return lhs.base() == rhs.base();
    }

    template <class value_type, class node_type>
    bool operator!=(const bidirectional_iterator<value_type, node_type> lhs, const bidirectional_iterator<value_type, node_type> rhs) {
        // std::cout << "Not equal non const" <<std::endl;
        return lhs.base() != rhs.base();
    }

    // non-member function overloads CONST

    template <class value_type, class value_type2, class node_type>
    bool operator==(const bidirectional_iterator<value_type, node_type> lhs, const bidirectional_iterator<value_type2, node_type> rhs) {
        // std::cout << "equal const" <<std::endl;
        return lhs.base() == rhs.base();
    }

    template <class value_type, class value_type2, class node_type>
    bool operator!=(const bidirectional_iterator<value_type, node_type> lhs, const bidirectional_iterator<value_type2, node_type> rhs) {
        // std::cout << "Not equal const" <<std::endl;
        return lhs.base() != rhs.base();
    }

}  // end of namespace
