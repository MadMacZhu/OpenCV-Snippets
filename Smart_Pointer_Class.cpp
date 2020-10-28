template <class T> class SmartPointer {
private:
	T* ref;
	unsigned* ref_count;

public:
	SmartPointer(T* ptr) {
		ref = ptr;
		ref_count = (unsigned*)malloc(sizeof(unsigned));
		*ref_count = 1;
	}

	SmartPointer(SmartPointer<T>& sptr) {
		ref = sptr.ref;
		ref_count = spter.ref_count;
		(*ref_count)++;
	}

	SmartPointer& operator=(SmartPointer& sptr) {
		if (this == &sptr)
			return *this;
		if (*ref_count > 0)
			remove();
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		(*ref_count)++;
		return *this;
	}

	~SmartPointer{
		remove();
	}

	T getValue() {
		return *ref;
	}

protected:
	void remove() {
		(*ref_count)--;
		if (*ref_count == 0) {
			delete ref;
			free(ref_count);
			ref = NULL;
			ref_count = NULL;
		}
	}

};