#include <iostream>
using namespace std;

template <class T>
struct two3node
{
    T k1,k2;                               
    two3node<T> * left;
    two3node<T> * middle;                  
    two3node<T> * right;
    int n;                                
};

template <class T>
struct usefulData
{
    T midValue;    
    two3node<T> * child;

    usefulData()
    {
        child = NULL;
    }

    usefulData (two3node<T>* c)
    {
        child = c;
    }

    usefulData (two3node<T>* c, T m)
    {
        child    = c;
        midValue = m;
    }

    usefulData<T> operator = (usefulData<T> & otherusefulData)
    {
        if (&otherusefulData != this)
        {
            child    = otherusefulData.child;
            midValue = otherusefulData.midValue;
        }

        return *this;
    }

    usefulData(usefulData<T> & otherusefulData)
    {
        child = otherusefulData.child;
        midValue = otherusefulData.midValue;
    }
};

template <class T>
class two3Tree
{

private:
    two3node<T> * root;


public:

    two3Tree()
    {
        root = NULL;
    }

    ~two3Tree()
    {
        if (root != NULL)                  
        {
            destroy(root);
        }
    }

    void destroy (two3node<T> * r)
    {
        if (r != NULL)
        {
            destroy (r -> left);
            destroy (r -> middle);
            destroy (r -> right);
            delete r;
        }
    }

    int isRotationPossible(two3node<T>* p, two3node<T>* r)
    {
        if (p != r)    
        {
            if (p -> n == 1)    
            {
                
                if( r -> n == 0 )
                {
                    if ( (p -> left == r) && (p -> middle -> n == 2) )  
                        return 2;           

                    else if ( (p -> middle == r) && ( p -> left -> n == 2) )    
                        return 1;           
                }

                
                else
                {
                    if (! ((p -> left -> n == 2) && (p -> middle -> n == 2)))   
                    {
                        if (p -> left == r)
                            return 1;            

                        else
                            return 2;             
                    }
                }
            }


            else                
            {
                if (r -> n == 0)    
                {
                    if ( (p -> left == r) && (p -> middle -> n == 2) )  
                    {
                        return 2;   
                    }

                    else if (p -> middle == r)      
                    {
                        if (p -> left -> n == 2)
                           return 1;           

                       else if (p -> right -> n == 2)
                          return 2;           
                    }

                    else                    
                    {
                        if ( p -> middle -> n == 2)
                            return 1;         
                    }
                }


                else                
                {
                    if ( (p -> left == r) && (p -> middle -> n == 1) )
                        return 1;         


                    else if (p -> middle == r)
                    {
                       if (p -> left -> n == 1)
                           return 2;        

                       else if (p -> right -> n == 1)
                          return 1;          
                    }

                    else
                    {
                       if (p -> middle -> n == 1)
                          return 2;      
                    }
                }
            }
        }

        return 0;   
    }



    usefulData<T> rotateRight (two3node<T>* p, two3node<T>* r, T d, two3node<T>* child)
    {

        if (r -> n == 0)
        {
            if ( (p -> n == 2) && ( p -> right == r) )   
            {
                r -> k1 = p -> k2;              
                r -> n = 1;

                p -> k2 = p -> middle -> k2;

                p -> middle -> n = 1;

                p -> right -> left = p -> middle -> right;

            }

            else    
            {
                r -> k1 = p -> k1;              
                r -> n = 1;                     

                p -> k1 = p -> left -> k2;

                p -> left -> n = 1;

                p -> middle -> left = p -> left -> right;
            }
        }

        else
        {
            if ( p -> n == 2 && p -> middle == r )     
            {
                p -> right -> k2 = p -> right -> k1;    

                p -> right -> k1 = p -> k2; 

                if (d < r -> k1)
                {
                    p -> k2 = r -> k2;
                    r -> k2 = r -> k1;
                    r -> k1 = d;
                }

                else if (d < r -> k2)
                {
                    p -> k2 = r -> k2;
                    r -> k2 = d;
                }

                else
                {
                    p -> k2 = d;
                }


                p -> right -> right  = p -> right  -> middle;
                p -> right -> middle = p -> right -> left;

                p -> right -> left   = child;

                p -> right -> n = 2;
            }

            else
            {
                p -> middle -> k2 = p -> middle -> k1;
                p -> middle -> k1 = p -> k1;

                if (d < r -> k1)
                {
                    p -> k1 = r -> k2;
                    r -> k2 = r -> k1;
                    r -> k1 = d;
                }

                else if (d < r -> k2)
                {
                    p -> k1 = r -> k2;
                    r -> k2 = d;
                }

                else
                {
                    p -> k1 = d;
                }

                p -> middle -> right = p -> middle -> middle;
                p -> middle -> middle = p -> middle -> left;

                p -> middle -> left   = child;

                p -> middle -> n = 2;
            }
        }

        return (NULL);
    }



    usefulData<T> rotateLeft (two3node<T>* p, two3node<T>* r, T d, two3node<T>* child)
    {

        if ( r -> n == 0)
        {
            if ( (p -> n == 2) && ( p -> middle == r) )
            {
                r -> k1 = p -> k2;
                r -> n = 1;

                p -> k2 = p -> right -> k1;

                p -> right -> k1 = p -> right -> k2;
                p -> right -> n = 1;

                p -> middle -> middle = p -> right -> left;

                p -> right -> left   = p -> right -> middle;
                p -> right -> middle = p -> right -> right;
            }

            else
            {
                r -> k1 = p -> k1;
                r -> n = 1;

                p -> k1 = p -> middle -> k1;

                p -> middle -> k1 = p -> middle -> k2;
                p -> middle -> n  = 1;

                p -> left -> middle = p -> middle -> left;

                p -> middle -> left   = p -> middle -> middle;
                p -> middle -> middle = p -> middle -> right;
            }

        }

        else
        {
            if ( p -> n == 2 && p -> right == r )
            {
                p -> middle -> k2 = p -> k2;

                if (d < r -> k1)
                {
                    p -> k2 = d;
                }

                else if (d < r -> k2)
                {
                    p -> k2 = r -> k1;
                    r -> k1 = d;
                }

                else
                {
                    p -> k2 = r -> k1;
                    r -> k1 = r -> k2;
                    r -> k2 = d;
                }

                p -> middle -> right = p -> right -> left;

                p -> right -> left  = p -> right -> middle;
                p -> right -> middle = p -> right -> right;
                p -> right -> right = child;

                p -> middle -> n = 2;
            }

            else
            {
                p -> left -> k2 = p -> k1;

                if (d < r -> k1)
                {
                    p -> k1 = d;
                }

                else if (d < r -> k2)
                {
                    p -> k1 = r -> k1;
                    r -> k1 = d;
                }

                else
                {
                    p -> k1 = r -> k1;
                    r -> k1 = r -> k2;
                    r -> k2 = d;
                }

                p -> left -> right = p -> middle -> left;

                p -> middle -> left  = p -> middle -> middle;
                p -> middle -> middle = p -> middle -> right;
                p -> middle -> right = child;

                p -> left -> n = 2;
            }
        }

        return (NULL);
    }

    bool insert(T d)
    {
        T temp = searchFor(d);

        if (temp != d)
        {
            two3node<T>* p = root;

            usefulData<T> s1 = insert(root, d, p);

            if (s1.child != NULL)
            {
                two3node<T> * temp = new two3node<T>;

                temp -> k1 = s1.midValue;
                temp -> n  = 1;

                temp -> left = root;
                temp -> middle  = s1.child;

                temp -> right = NULL;
                root = temp;
            }

            return true;
        }

        else
            cout << "\nДанный элемент уже есть\n";

        return false;
    }

    usefulData<T> insert (two3node<T>* & r, T d, two3node<T>* p)
    {
        if( r == nullptr)
        {
            two3node<T>* temp = new two3node<T>;

            temp -> k1 = d;
            temp -> left = temp -> middle = temp -> right = NULL;

            temp -> n = 1;
            r = temp;

            return (NULL);
        }

        else if (r -> left == nullptr)
        {
            if ( r -> n == 1)
            {

                if ( d < r -> k1)
                {
                    r -> k2 = r -> k1;
                    r -> k1 = d;
                }

                else
                    r -> k2 = d;

                r -> n = 2;

                return (NULL);
            }


            else
            {
                usefulData<T> s1;


                int e = isRotationPossible(p,r);

                if (e == 1)
                    s1 = rotateRight(p,r,d, NULL);

                else if (e == 2)
                    s1 = rotateLeft(p,r,d, NULL);

                else
                    s1 = split3node(r, d, NULL);

                return s1;
            }
        }

        else
        {
            if ( r -> n == 1)
            {
                if (d < r -> k1)
                {
                    usefulData<T> s1 = insert (r -> left, d, r);

                    
                    if (s1.child != nullptr)
                    {
                    
                        r -> k2 = r -> k1;
                        r -> k1 = s1.midValue;

                        r -> right = r -> middle;
                        r -> middle = s1.child;

                        r -> n = 2;
                    }
                }

                else if (d > r -> k1)
                {
                    usefulData<T> s1 = insert (r -> middle, d, r);

                    if (s1.child != NULL)
                    {
                         r -> k2 = s1.midValue;
                        r -> right = s1.child;

                        r -> n = 2;
                    }
                }

                return (NULL);
            }


            else
            {
                usefulData<T> s1;

                if ( d < r -> k1)
                     s1 = insert (r -> left, d, r);

                else if (d < r -> k2)
                     s1 = insert (r -> middle, d, r);

                else
                     s1 = insert (r -> right, d, r);

                if (s1.child != NULL)
                {

                    int e = isRotationPossible(p ,r);

                    if (e == 1)
                        s1 = rotateRight(p ,r ,s1.midValue, s1.child);

                    else if (e == 2)
                        s1 = rotateLeft(p ,r ,s1.midValue, s1.child);

                    else
                        s1 = split3node(r, s1.midValue, s1.child);

                    return s1;
                }

                return (NULL);
            }
        }

    }




    usefulData<T> split3node (two3node<T>* current, T k, two3node<T>* child)
    {
        T mid;

        two3node<T>* temp = new two3node<T>;
        temp -> n = 1;

        temp -> left = temp -> middle = temp -> right = NULL;


        if (k < current -> k1)
        {
            mid = current -> k1;

            temp -> k1    = current -> k2;
            current -> k1 = k;

            if (current -> left != NULL)
            {
                temp -> left = current -> middle;
                temp -> middle = current -> right;
                current -> middle = child;
            }
        }


        else if (k < current -> k2)
        {
            mid = k;

            temp -> k1    = current -> k2;

            if (current -> left != NULL)
            {
                temp -> left = child;
                temp -> middle = current -> right;
            }
        }

        else
        {
            mid = current -> k2;

            temp -> k1 = k;

            if(current -> left != NULL)
            {
                temp -> left = current -> right;
                temp -> middle = child;
            }
        }

        current -> right = NULL;
        current -> n = 1;

        usefulData<T> s1(temp, mid);
        return s1;
    }

    usefulData<T> merge(two3node<T>* p, two3node<T>* &r, two3node<T>* child)
    {

        if( (p -> n == 2) && (p -> right == r) )
        {
            p -> middle -> k2 = p -> k2;

            p -> middle -> n  = 2;

            p -> middle -> right = child;

            child = NULL;
        }

        else
        {
            if (p -> left == r)
            {
                p -> middle -> k2 = p -> middle -> k1;
                p -> middle -> k1 = p -> k1;

                p -> middle -> n = 2;

                p -> middle -> right = p -> middle -> middle;
                p -> middle -> middle = p -> middle -> left;
                p -> middle -> left  = child;

                child = p -> middle;

                p -> left   = p -> middle;
                p -> middle = p -> right;
            }

            else
            {
                p -> left -> k2 = p -> k1;

                p -> left -> n = 2;

                p -> left -> right = child;

                child = p -> left;

                p -> middle = p -> right;
            }

            if (p -> n == 2)
            {
                p -> k1 = p -> k2;
                child  = NULL;
            }
        }


        p -> right = NULL;

        p -> n--;

        r -> left = r -> middle = r -> right = NULL;
        delete r;
        r = NULL;


        return (child);
    }

    void deleteNode (T d)
    {
        two3node<T> * p = root;

        Delete(root,d,p);
    }

    usefulData<T> Delete(two3node<T>* r , T d, two3node<T>* p)
    {
        if (r != NULL)
        {

            if (r -> left != NULL)
            {

                usefulData<T> s1(NULL);

                if (r -> n == 1)
                {
                    if (d != r -> k1)
                    {
                        if (d < r -> k1)
                        {
                            s1 = Delete (r -> left, d, r);
                        }

                        else
                            s1 = Delete (r -> middle, d, r);

                        if(s1.child == NULL)
                            return s1;
                    }
                }


                else
                {
                    if ( (d != r -> k1) && ( d != r -> k2) )
                    {
                        if (d < r -> k1)
                        {
                            s1 = Delete (r -> left, d, r);
                        }

                        else if (d < r -> k2)
                        {
                            s1 = Delete (r -> middle, d, r);
                        }

                        else
                            s1 = Delete (r -> right, d, r);

                        if(s1.child == NULL)
                            return s1;
                    }
                }


                if(root -> n == 0)
                {
                    root -> left = root -> middle = root -> right = NULL;
                    delete root;
                    root = s1.child;

                    r    = root;

                    return (NULL);
                }


                if (s1.child != NULL)
                {
                    int e = isRotationPossible(p,r);

                    if (e == 1)
                        s1 =  rotateRight(p,r,s1.midValue,s1.child);

                    else if (e == 2)
                        s1 =  rotateLeft(p,r,s1.midValue,s1.child);

                    else
                        s1 = merge(p,r,s1.child);

                    return s1;
                }

                two3node<T>* current;
                T temp;

                if ( (r -> n == 2) && (r -> k2 == d) )
                {
                    temp    = r -> k2;
                    current = r -> middle;

                    p = r;

                    while (current -> left != NULL)
                    {
                        p = current;

                        if (current -> n == 1)
                        {
                            current = current -> middle;
                        }

                        else
                        {
                            current = current -> right;
                        }
                    }


                    if (current -> n == 1)
                    {
                        r -> k2       = current -> k1;
                        current -> k1 = temp;
                    }

                    else
                    {
                        r -> k2       = current -> k2;
                        current -> k2 = temp;
                    }
                }


                else
                {
                    temp    = r -> k1;
                    current = r -> left;

                    p = r;

                    while (current -> left != NULL)
                    {
                        p = current;

                        if (current -> n == 1)
                        {
                           current = current -> middle;
                        }

                        else
                        {
                            current = current -> right;
                        }
                    }


                    if (current -> n == 1)
                    {
                        r -> k1       = current -> k1;
                        current -> k1 = temp;
                    }

                    else if (current -> n == 2)
                    {
                        r -> k1       = current -> k2;
                        current -> k2 = temp;
                    }
                }

                    current -> n--;
                    r = current;
            }

                else if ((r -> left == NULL) && ( (r -> k1 == d) || (r -> k2 == d) ))
                {
                    if (r -> n == 2)
                    {
                        if (r -> k1 == d)
                        {
                            r -> k1 = r -> k2;
                        }
                    }

                    r -> n --;
                }

                if ( (r -> n == 0) && (p == r) )
                {
                    delete r;
                    root = NULL;
                }

                else if (r -> n == 0)
                {

                    usefulData<T> s1;

                    int e = isRotationPossible(p,r);


                    if (e == 1)
                        s1 =  rotateRight(p,r,s1.midValue,NULL);

                    else if (e == 2)
                        s1 =  rotateLeft(p,r,s1.midValue,NULL);

                    else
                        s1 = merge(p,r,NULL);

                    return s1;
                }

            }

            else
                cout << "\nДерево уже пустое";

            return (NULL);
        }

    T searchFor(T item)
    {
        return search(root, item);
    }

    T search (two3node<T>* r, T d)
    {
        if (r != NULL)
        {
            if (r -> n == 1)
            {
                if (d == r -> k1)
                    return r -> k1;

                else if (d < r -> k1)
                {
                    return search (r -> left , d);
                }

                else
                {
                    return search (r -> middle, d);
                }
            }

            else
            {
                if (d == r -> k1)
                    return r -> k1;

                else if (d == r -> k2)
                    return r -> k2;

                else if (d < r -> k1)
                {
                    return search (r -> left , d);
                }

                else if (d < r-> k2)
                {
                    return search (r -> middle, d);
                }

                else
                    return search (r -> right, d);
            }
        }

        else
            return -99999999;
    }

    void printTree()
    {
       cout << "\nДерево";
       print(root);
    }

    void print (two3node<T>* r)
    {
        if(r != NULL)
        {
            if (r -> n == 1)
            {
                print (r -> left);
                cout << " "<< r -> k1;
                print (r -> middle);
            }

            else
            {
                print (r -> left);
                cout << " "<< r -> k1;
                print (r -> middle);
                cout << " "<< r -> k2;
                print (r -> right);
            }
        }

        else
            cout << "\nДерево пусто";
    }



    void displayFunctions()
    {
        cout << "\n\n\nФункции";
        cout << "\n1)Вставить \n2)Удалить \n3)Поиск \n4)Вывод\n\n";
        cout << "\nВведите номер ф; Чтобы выйти, напишите -1 \n:";
    }
};

void driver()
{
    two3Tree<int> tree1;

    int userInput = 0;
    int data;

    while (userInput != -1)
    {
        tree1.displayFunctions();
        cin >> userInput;

        if (userInput == 1)
        {
            cout << "\nВведите данные для дерева";
            cin  >> data;

            tree1.insert(data);

            cout << "\nПосле ввода";
            tree1.printTree();
        }

        else if (userInput == 2)
        {
            cout << "\nВведите данные для удаления";
            cin  >> data;

            tree1.deleteNode(data);

            cout << "\nПосле удаления";
            tree1.printTree();
        }

        else if (userInput == 3)
        {
            cout << "\nВведите данные для поиска";
            cin  >> data;

            if(tree1.searchFor(data) != -99999999)
                cout << "\nЭлемент найден ";
            else
                cout << "\nЭлемент не найден";
        }

        else if (userInput == 4)
        {
            tree1.printTree();
        }
    }
}



int main()
{
    driver();
    return 0;
}