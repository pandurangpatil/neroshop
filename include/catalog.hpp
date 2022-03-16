// filename: catalog.hpp
//#pragma once // use #ifndef _HPP, #define _HPP, and #endif instead for portability

#ifndef CATALOG_HPP_NEROSHOP // recommended to add unique identifier like _NEROSHOP to avoid naming collision with other libraries
#define CATALOG_HPP_NEROSHOP
// neroshop
#include "debug.hpp"
#include "db.hpp"
// dokun-ui
#include <box.hpp>
// STL
#include <iostream>
#include <memory> // std::shared_ptr, std::make_shared

namespace neroshop {
class Catalog {
public:
    Catalog();
    ~Catalog();
    void draw();
    void draw(int x, int y);
    void center(int window_width, int window_height);
    void add_box();
    // for entire catalog
    void set_position(int x, int y);
    void set_width(int width);
    void set_height(int height);
    void set_size(int width, int height);
    // for each individual boxes
    Box * get_box(int index) const;
    int get_x() const;
    int get_y() const;
    Vector2i get_position() const;
    int get_width() const;
    int get_height() const;
    Vector2i get_size() const;
    //get_capacity(); // number of boxes that can be lined up horizontally
    //get_row_capacity(); // number of boxes that can be lined up vertically
private:
    unsigned int width; 
    unsigned int height;
    //unsigned int columns;
    //unsigned int rows;
    std::vector<std::shared_ptr<Box>> box_list;
    void initialize();
    void update(); // updates size and width of boxes
    // box contents
    void add_contents(int box_index); // adds everything
    // product data
    void fetch_product_data();
    /*void add_product_image();
    void add_product_price();
    void add_product_stars(); // star ratings
    void add_product_star_label();
    void add_product_quantity_spinner();
    void add_heart(); // favorite or wishlist
    void add_cart_button(); // add-to-cart button*/
    // views: list_view, grid_view
};
}
#endif
// https://github.com/kyliau/ShoppingCart/blob/master/Catalog.cpp
