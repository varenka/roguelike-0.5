#ifndef ITEM_H
#define ITEM_H

class item
{
    public:
        item();
        virtual ~item();
        void use();

        int id;
};

#define PEANUT_BAG 100
#define COOKIE 101
#define SOUP 102

#endif
