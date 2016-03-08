class matrix {
	int * A;
	int rows,cols;
	int m;
	public:
	matrix(int horiz,int vert, int mod);
	void setup(int *,int);
	void set_entry(int,int,int);
	void display();
	int get_entry(int r,int c);
    void scalar_row(int row, int scalar);
    void add_row(int row, int row2, int scalar);
	void RREF();
	void solution(FILE *);
	void clean();
	};