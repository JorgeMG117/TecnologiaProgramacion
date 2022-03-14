// Hugo Lázaro Zapata 801758
// Jorge Martinez Gil 801369

#pragma once

template<typename T>
class dynamic_stack{

private:
	class nodo{
		public:
			T dato;
			nodo* sig;
	};
	nodo* cima;
	int total;

public:
	dynamic_stack() : total(0), cima(nullptr)
	{}

	bool push(const T& e){
		if(total == 0){
			cima = new nodo;
			cima->dato = e;
			cima->sig = nullptr;
		}
		else{
			nodo* nuevo = new nodo;
			nuevo->dato = e;
			nuevo->sig = cima;
			cima = nuevo;
		}
		total++;
		return true;
	}

	bool pop(){
		if(total > 1){
			nodo* aux = cima;
			cima = cima->sig;
			delete aux;
			total--;
			return true;
			
		}
		else if(total == 1){
			delete cima;
			cima = nullptr;
			total--;
			return true;
		}
		else{
			return false;
		}
	}

	friend class const_iterator;

	class const_iterator
	{
	private:
		const dynamic_stack<T>& stk;
		nodo* i;
	public:
		const_iterator(const dynamic_stack& stk_, nodo* i_) : stk(stk_), i(i_)
		{ }

		const_iterator& operator++()
		{
			i=i->sig;
			return (*this);
		}

		const T& operator*() const { return i->dato; }

		bool operator!=(const const_iterator& that) const { return i != that.i; }

	};

	const_iterator begin() const { return const_iterator(*this,this->cima); }
	
	const_iterator end() const { return const_iterator(*this,nullptr); }

};
