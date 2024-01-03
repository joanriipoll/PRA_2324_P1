#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	//redimensionar el array
        void resize(int new_size){
                T* new_arr = new T[new_size];
                for(int i = 0; i < std::min(max, new_size); i++){
                        new_arr[i] = arr[i];
                }
                delete[] arr;
                arr = new_arr;
                max = new_size;
        }

    public:
        // miembros públicos, incluidos los heredados de List<T>
	void insert(int pos, T e) override{
		if(pos < 0 || pos > n) throw std::out_of_range("Posicion fuera de rango");
			
		if(n >= max) resize(max*2);

		if(n == 0){
			arr[0] = e;

		}else if(pos == n){

			arr[pos] = e;

		}else{

			for(int i=n; i>=pos; i--){
				arr[i] = arr[i-1];
				}
			}
			arr[pos] = e;
			n++;
	}

	//Inserta el elmento e al final de la lista
	void append(T e) override{
		insert(n,e);
	}

	//Inserta un elemento al principio de la lista
	void prepend(T e) override {
		insert(0, e);
	}

	//Elimina y devuelve el elmento situado en la posicion pos
	T remove(int pos) override{
		if(pos < 0 || pos > n - 1){
			throw std::out_of_range("ERROR, fuera de rango");
		}
		
		T elemento_a_devolver = arr[pos];
		
		for(int i = pos; i < n -1; i++){
			arr[pos] = arr[pos + 1];
		}
		
		n--;
		return elemento_a_devolver;
	}

	//Devuelce el elemento situado en la posicion pos
	T get(int pos) override{
		if(pos < 0 || pos >= n ){
			throw std::out_of_range("ERROR, fuera de rango");
		}
		return arr[pos];
	}

	//Devuelve la primera ocurrencia donde se encuentre el elemetno e o -1 si no se encuentra
	int search(T e) override{
		for(int i = 0; i < n; i++){
			if(arr[i] = e){
				return i;
			}
		}
		return -1;
	}

	//Indica si la lista está vacia
	bool empty() override{
		 return n==0;
	}
	
	//Devuelve el numero de elementos de la lista
	int size() override{
		return n;
	}

	//metodo construcotr sin argumentos
	ListArray() {
		arr = new T[MINSIZE];
		n = 0;
	}

	//Método destructor
	~ListArray() {
		delete[] arr;
	}

	// Sobrecarga el operador[]
	T operator[](int pos){
		if(pos < 0 || pos > size()-1){
			throw std::out_of_range("Error, fuera de rango");
		}
		else {
			return arr[pos];
		}
	}

	//Sobrecarga el operador <<
	friend std::ostream&operator<<(std::ostream &out, const ListArray<T> &list){
		out << "[";
		for(int i = 0; i < list.n; i++){
			out << list.arr[i];
			if(i < list.n - 1){
				out << ",";
			}
		}
		out << "]";
		return out;
	}
};
