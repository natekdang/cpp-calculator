#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
	    OpCommand() : Command() {};
	    OpCommand(double val) {
	        root = new Op(val);
	    };
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
	    AddCommand() : Command() {};
	    AddCommand(Command *command, int val) {
	        root = new Add(command->get_root(), new Op(val) );
	    };
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
	    SubCommand() : Command() {};
	    SubCommand(Command *command, int val) {
	        root = new Sub(command->get_root(), new Op(val) );
	    };
};

class MultCommand : public Command {
	//MultCommand Code Here
	public: 
		MultCommand() : Command() {};
		MultCommand(Command *command, int val) {
	        root = new Mult(command->get_root(), new Op(val) );
		};
};

class DivideCommand : public Command {
	//MultCommand Code Here
	public: 
		DivideCommand() : Command() {};
		DivideCommand(Command *command, int val) {
	        root = new Divide(command->get_root(), new Op(val) );
		};
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public: 
		SqrCommand() : Command() {};
		SqrCommand(Command *command) {
	        root = new Sqr(command->get_root() );
		};
};

class ModuloCommand : public Command {
	//ModuloCommand Code Here, no cpp
	public: 
		ModuloCommand() : Command() {};
		ModuloCommand(Command *command, int val) {
			root = new Modulo(command->get_root(), new Op(val) ); //mod function 
		}
};



#endif //__COMMAND_CLASS__