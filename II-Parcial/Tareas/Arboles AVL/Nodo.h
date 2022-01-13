template<class T>
class Nodo
{
    private:
        T key;
        int height;
        Nodo<T> * left;
        Nodo<T> * right;
    public:
        Nodo<T>(T k);
        T getKey();
        int getHeigth();
        Nodo<T>* getLeft();
        Nodo<T>* getRigth();
        void setKey(T);
        void setHeigth(int);
        void setLeft(Nodo<T>*);
        void setRigth(Nodo<T> *);
};

template<class T>
Nodo<T>::Nodo(T k)
{
    this->height = 1;
    this->key = k;
    this->left = NULL;
    this->right = NULL;
}

template<class T>
T Nodo<T>::getKey(){
    return this->key;
}

template<class T>
int Nodo<T>::getHeigth() {
    return this->height;
}

template<class T>
Nodo<T>* Nodo<T>::getLeft() {
    return this->left;
}

template<class T>
Nodo<T>* Nodo<T>::getRigth() {
    return this->right;
}

template<class T>
void Nodo<T>::setKey(T key) {
    this->key = key;
}

template<class T>
void Nodo<T>::setHeigth(int h) {
    this->height = h;
}

template<class T>
void Nodo<T>::setLeft(Nodo<T>* L)
{
    this->left = L;
}

template<class T>
void Nodo<T>::setRigth(Nodo<T> * R)
{
    this->right = R;
}