#include <iostream>
#include <cmath>
#include <istream>
#include <fstream>
using namespace std;

// Ahmet Alper Yılmaz --- g++ main.cpp -o main --- ./main input1.txt

class Neuron{
	protected:
		double value_of_z;
		double activated_value;
	public:
		virtual void activate() = 0;
		Neuron(){} // default constructor
		double get_value_a(){ return activated_value; } // getting activated value
		void set_value_z(double y1, double y2){ value_of_z = y1 + y2; } // new z value
		void print_out(){ cout << activated_value << endl; } // print activated value
};

class SigmoidNeuron:public Neuron{
	public:
		void activate(); // sigmoid formula
		SigmoidNeuron(){} // default constructor
		SigmoidNeuron(int y){ value_of_z = y; activated_value = y; } // initial constructor
};

class ReluNeuron:public Neuron{
	public:
		void activate(); // relu formula
		ReluNeuron(){} // default constructor
		ReluNeuron(int y){ value_of_z = y; activated_value = y; } // initial constructor
};

class LReluNeuron:public Neuron{
	public:
		void activate(); // lrelu formula
		LReluNeuron(){} // default constructor
		LReluNeuron(int y){ value_of_z = y; activated_value = y; } // initial constructor
};

class Layer{
	Neuron * neuronarray;
	public:
		Layer(){ neuronarray = NULL; } // default constructor
		Layer(const int, int, int *, int); // Layer 0
		Layer(Layer *, int, int, int, int); // Layer 1,2,......
		~Layer(){ delete[] neuronarray; } // destructor
};

class Network{
	Layer ** layerarray;
	int num_layers;
	public:
		Network(){ layerarray = NULL; } // default constructor
		Network(const int); // constructor
		~Network(); // destructor
		Layer ** getlayerarray(){ return layerarray;} //getter
};

Layer::Layer(const int layer, int how_many, int * initial_x_array, int initial_type){
	if(initial_type == 0){
		cout << "Layer 0:"<<endl;
		this->neuronarray = new SigmoidNeuron[how_many];
		for(int i=0; i < how_many; i++){
			this->neuronarray[i] = SigmoidNeuron(initial_x_array[i]);
			cout << initial_x_array[i] << endl;
		}
	}
	else if (initial_type == 1){
		cout << "Layer 0:"<<endl;
		this->neuronarray = new LReluNeuron[how_many];
		for(int i=0; i < how_many; i++){
			this->neuronarray[i] = LReluNeuron(initial_x_array[i]);
			cout << initial_x_array[i] << endl;
		}
	}
	else if (initial_type == 2){
		cout << "Layer 0:"<<endl;
		this->neuronarray = new ReluNeuron[how_many];
		for(int i=0; i < how_many; i++){
			this->neuronarray[i] = ReluNeuron(initial_x_array[i]);
			cout << initial_x_array[i] << endl;
		}
	}
}

Layer::Layer(Layer * previous_layer, int how_many, int howmany_prev, int type_of_neuron, int counter){
	double ** W_matrix = new double *[how_many];
	for (int i = 0; i < how_many; i++){
		W_matrix[i] = new double[howmany_prev];	
	}
	for (int i = 0; i < how_many; i++){
		for (int j = 0; j < howmany_prev; j++){
			W_matrix[i][j] = 0.1;
		}	
	}
	double * B_matrix = new double[how_many];		
	for (int j = 0; j < how_many; j++){
		B_matrix[j] = 0.1;			
	}
	if(type_of_neuron == 0){
		cout << "Layer "<< counter << ":" << endl;
		this->neuronarray = new SigmoidNeuron[how_many];
		double new_z;
		for(int i = 0; i < how_many; i++){
			new_z = 0;
			for(int j = 0; j < howmany_prev; j++){
				double old = previous_layer->neuronarray[j].get_value_a();
				new_z += W_matrix[i][j] * old; 
			}
			this->neuronarray[i].set_value_z(new_z, B_matrix[i]);
			neuronarray[i].activate();
			neuronarray[i].print_out();  
		}
	}
	else if (type_of_neuron == 1){
		cout << "Layer "<< counter << ":" << endl;
		this->neuronarray = new LReluNeuron[how_many];
		double new_z;
		for(int i = 0; i < how_many; i++){
			new_z = 0;
			for(int j = 0; j < howmany_prev; j++){
				double old = previous_layer->neuronarray[j].get_value_a();
				new_z += W_matrix[i][j] * old; 
			}
			this->neuronarray[i].set_value_z(new_z, B_matrix[i]);
			neuronarray[i].activate();
			neuronarray[i].print_out();  
		}	
	}
	else if (type_of_neuron == 2){
		cout << "Layer "<< counter << ":" << endl;
		this->neuronarray = new ReluNeuron[how_many];
		double new_z;
		for(int i = 0; i < how_many; i++){
			new_z = 0;
			for(int j = 0; j < howmany_prev; j++){
				double old = previous_layer->neuronarray[j].get_value_a();
				new_z += W_matrix[i][j] * old; 
			}
			this->neuronarray[i].set_value_z(new_z, B_matrix[i]);
			neuronarray[i].activate();
			neuronarray[i].print_out();  
		}
	}
	for(int a = 0; a < how_many; a++){
		delete W_matrix[a];
	}
	delete[] W_matrix;
	delete[] B_matrix;
}

Network::Network(const int layer){
	layerarray = new Layer*[layer];
	num_layers = layer;
}

Network::~Network(){ // destructor
	for(int a = 0; a < num_layers; a++){
		delete layerarray[a];
	}
	delete[] layerarray;
}

void SigmoidNeuron::activate(){
	activated_value = 1.0 / (1.0 + exp(-value_of_z));
}

void ReluNeuron::activate(){
	activated_value = fmax(0,value_of_z);
}

void LReluNeuron::activate(){
	activated_value = fmax(0.1*value_of_z,value_of_z);
}

int main(int argc, char *argv[]){
	for(int a = 1; a < argc; a++){
		ifstream infile(argv[a]); // input.txt
		if(!infile){
			cerr << "Error occured when opening the file" << endl;
			exit(EXIT_FAILURE);
		}
		int layer_counter = 0;
		int input_control = 0;
		int num;
		infile >> num;
		const int num_layers = num; // number of layers
		int* array_of_x = new int[num_layers];
		int* type_neurons = new int[num_layers];
		int* num_neurons = new int[num_layers];
		for(int b = 0; b < num_layers; b++) infile >> num_neurons[b];
		for(int b = 0; b < num_layers; b++) infile >> type_neurons[b];
		try{ // try-catch for invalid input shapes
            while(infile.peek() != EOF){
                if(num_layers > input_control) infile >> array_of_x[input_control];
                else throw 19;	
                input_control++;
            }
            if(num_layers != input_control) throw 19;
        }
        catch(int covid){
			delete[] array_of_x;
			delete[] type_neurons;
            delete[] num_neurons;
			cout << "Input shape does not match!" << endl;
            exit(EXIT_FAILURE);
        }
		Network * networkobj = new Network(num_layers);
		while(layer_counter < num_layers){
			if(layer_counter == 0){
				try{ // try-catch for invalid neuron types
					int c = 0;
					while(num_layers > c){	
						if(type_neurons[c] < 0 || type_neurons[c] > 2) throw 19;
						c++;
					}
					Layer * layerobj = new Layer(num_layers,num_neurons[layer_counter],array_of_x,type_neurons[0]);
					networkobj->getlayerarray()[layer_counter] = layerobj;
					layer_counter++;	
				}
				catch(int covid){
					delete[] array_of_x;
					delete[] type_neurons;
					delete[] num_neurons;
					cout << "Unidentified activation function!" << endl;
					exit(EXIT_FAILURE);
				}
			}
			else if(layer_counter < num_layers){
				try{ // try-catch for invalid neuron types
					int c = 0;
					while(num_layers > c){	
						if(type_neurons[c] < 0 || type_neurons[c] > 2) throw 19;
						c++;
					}
					Layer * temp_layer = networkobj->getlayerarray()[layer_counter-1];
					Layer * layerobj = new Layer(temp_layer,num_neurons[layer_counter],num_neurons[layer_counter-1],type_neurons[layer_counter],layer_counter);
					networkobj->getlayerarray()[layer_counter] = layerobj;
					layer_counter++;	
				}
				catch(int covid){
					delete[] array_of_x;
					delete[] type_neurons;
					delete[] num_neurons;
					cout << "Unidentified activation function!" << endl;
					exit(EXIT_FAILURE);
				}
			}
		}
		delete[] array_of_x;
		delete[] type_neurons;
		delete[] num_neurons;
		delete networkobj;
	}
	return EXIT_SUCCESS;
}
