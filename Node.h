#include <ostream>

template <typename T> 
class Node {
    public:
       	//Elemento almacenado, de tipo genérico T
	T data;

	//Puntero al siguiente nodo de la secuencia.
	Node<T>* next;

	//Metodo constructor
	Node(T data, Node<T>* next=nullptr){
		this->data = data;
		this->next = next;
	}
	
	//Sobrecarga el operador para que imprima una instacia de node.
	friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
	
		out <<"La instancia de Node<T> es: " << node.data;
		return out;
	}
	
    
};
