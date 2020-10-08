using namespace std;
template <typename T> class list;
class Deque{
private:
    class Element
    {
    public:
        Element *next;
        Element *prev;
        int val;

        Element(): next(NULL),prev(NULL){val = 0;}
        ~Element(){}
    };
    Element* top;
    Element* down;
    int size;

public:
    template <class T>
    void push_front(const T & new_element){
        Element * add = new Element;
        add->val = new_element;
        if( top == NULL){
            top = add;
        }else{
            Element *item;
            for(item = down; item -> prev!=0 ; 
item = item -> prev){
                item = add;
            }
        }
        size ++;
    }
    template <class T>
    void push_back(const T & new_element)
    {
        Element * add = new Element;
        add->val = new_element;
        if( down == NULL){
            down = add;
        }else{
            Element *item;
            int x = 0;
            for(item = top; item->next != 0 ; item = item -> next){
                item = add;
                x++;
            }
        }
        size++;
    }
    void pop_front(){
        Element * del = top;
        top = top -> next;
        delete del;
        size --;
    }
    void pop_back(){
        Element * del = down;
        down = down -> prev;
        delete del;
        size --;
    }
    void clear()
    {
        Element *item = top;
        Element *del = top;
        while(del != NULL)
        {
            item = item->next;
            delete del;
            del = item;
        }
        top = NULL;
        size = 0;
    }
    int GetElement()const{
        Element *item;
        int x = 1;
        for(item = top ; x > 1 ; x--){
            item = item->next;
        }
        return item->val;
    }
    int GetFirstElement()const{
        Element* item;
        int x = 1;
        for (item = top ; x = 1 ; x--){
            return item->val;
        }
    }
    int GetLast()const{
        Element *item = down;
        return item->val;
    }

    int GetLastElement()const{
        Element *item = down;
        cout << "Size of deque is" << size;
        for(int x = 1; x < size ; x++){
            item = item->next;
        }
        return item->val;
    }
    Deque(): top(NULL),down(NULL),size(0){}

    ~Deque(){ clear();}
};
