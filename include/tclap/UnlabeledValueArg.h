
/****************************************************************************** 
 * 
 *  file:  UnlabeledValueArg.h
 * 
 *  Copyright (c) 2003, Michael E. Smoot .
 *  All rights reverved.
 * 
 *  See the file COPYING in the top directory of this distribution for
 *  more information.
 *  
 *  THE SOFTWARE IS PROVIDED _AS IS_, WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 *  DEALINGS IN THE SOFTWARE.  
 *  
 *****************************************************************************/ 


#ifndef TCLAP_UNLABELED_VALUE_ARGUMENT_H
#define TCLAP_UNLABELED_VALUE_ARGUMENT_H

#include <string>
#include <vector>
#include <sstream>
#include <tclap/Visitor.h>
#include <tclap/Arg.h>
#include <tclap/ValueArg.h>
#include <tclap/CommandLine.h>

namespace TCLAP {

/**
 * The basic unlabeled argument that parses a value.
 * This is a template class, which means the type T defines the type
 * that a given object will attempt to parse when an UnlabeledValueArg
 * is reached in the list of args that the CmdLine iterates over.
 */
template<class T>
class UnlabeledValueArg : public ValueArg<T>
{

#ifdef TWO_STAGE_NAME_LOOKUP
	//If compiler has two stage name lookup (as gcc >= 3.4 does)
	//this is requried to prevent undef. symbols
	using ValueArg<T>::_ignoreable;
	using ValueArg<T>::_hasBlanks;
	using ValueArg<T>::_extractValue;
	using ValueArg<T>::_typeDesc;
	using ValueArg<T>::_name;
	using ValueArg<T>::_description;
	using ValueArg<T>::_alreadySet;
#endif

	public:

		/**
		 * UnlabeledValueArg constructor.
		 * Note that this constructor does not have a required flag. Any 
		 * unlabeled argument added to the CmdLine is by default required.
		 * If you want optional, unlabeled arguments then use an 
		 * UnlabeledMultiArg.
		 * \param name - A one word name for the argument.  Can be
		 * used as a long flag on the command line.
		 * \param desc - A description of what the argument is for or
		 * does.
		 * \param value - The default value assigned to this argument if it
		 * is not present on the command line.
		 * \param typeDesc - A short, human readable description of the
		 * type that this object expects.  This is used in the generation
		 * of the USAGE statement.  The goal is to be helpful to the end user
		 * of the program.
		 * \param ignoreable - Allows you to specify that this argument can be
		 * ignored if the '--' flag is set.  This defaults to false (cannot
		 * be ignored) and should  generally stay that way unless you have 
		 * some special need for certain arguments to be ignored.
		 * \param v - Optional Vistor.  You should leave this blank unless
		 * you have a very good reason.
		 */
		UnlabeledValueArg( const std::string& name, 
			               const std::string& desc, 
				           T value,
				           const std::string& typeDesc,
						   bool ignoreable = false,
				           Visitor* v = NULL); 

		/**
		 * UnlabeledValueArg constructor.
		 * Note that this constructor does not have a required flag. Any 
		 * unlabeled argument added to the CmdLine is by default required.
		 * If you want optional, unlabeled arguments then use an 
		 * UnlabeledMultiArg.
		 * \param name - A one word name for the argument.  Can be
		 * used as a long flag on the command line.
		 * \param desc - A description of what the argument is for or
		 * does.
		 * \param value - The default value assigned to this argument if it
		 * is not present on the command line.
		 * \param typeDesc - A short, human readable description of the
		 * type that this object expects.  This is used in the generation
		 * of the USAGE statement.  The goal is to be helpful to the end user
		 * of the program.
		 * \param parser - A CmdLine parser object to add this Arg to
		 * \param ignoreable - Allows you to specify that this argument can be
		 * ignored if the '--' flag is set.  This defaults to false (cannot
		 * be ignored) and should  generally stay that way unless you have 
		 * some special need for certain arguments to be ignored.
		 * \param v - Optional Vistor.  You should leave this blank unless
		 * you have a very good reason.
		 */
		UnlabeledValueArg( const std::string& name, 
			               const std::string& desc, 
				           T value,
				           const std::string& typeDesc,
						   CmdLine& parser,
						   bool ignoreable = false,
				           Visitor* v = NULL ); 					
						
		/**
		 * UnlabeledValueArg constructor.
		 * Note that this constructor does not have a required flag. Any 
		 * unlabeled argument added to the CmdLine is by default required.
		 * If you want optional, unlabeled arguments then use an 
		 * UnlabeledMultiArg.
		 * \param name - A one word name for the argument.  Can be
		 * used as a long flag on the command line.
		 * \param desc - A description of what the argument is for or
		 * does.
		 * \param value - The default value assigned to this argument if it
		 * is not present on the command line.
		 * \param allowed - A vector of type T that where the values in the
		 * vector are the only values allowed for the arg.
		 * \param ignoreable - Allows you to specify that this argument can be
		 * ignored if the '--' flag is set.  This defaults to false (cannot
		 * be ignored) and should  generally stay that way unless you have 
		 * some special need for certain arguments to be ignored.
		 * \param v - Optional Vistor.  You should leave this blank unless
		 * you have a very good reason.
		 */
		UnlabeledValueArg( const std::string& name, 
			               const std::string& desc, 
				           T value,
				           const std::vector<T>& allowed,
						   bool ignoreable = false,
				           Visitor* v = NULL ); 

		
		/**
		 * UnlabeledValueArg constructor.
		 * Note that this constructor does not have a required flag. Any 
		 * unlabeled argument added to the CmdLine is by default required.
		 * If you want optional, unlabeled arguments then use an 
		 * UnlabeledMultiArg.
		 * \param name - A one word name for the argument.  Can be
		 * used as a long flag on the command line.
		 * \param desc - A description of what the argument is for or
		 * does.
		 * \param value - The default value assigned to this argument if it
		 * is not present on the command line.
		 * \param allowed - A vector of type T that where the values in the
		 * vector are the only values allowed for the arg.
		 * \param parser - A CmdLine parser object to add this Arg to
		 * \param ignoreable - Allows you to specify that this argument can be
		 * ignored if the '--' flag is set.  This defaults to false (cannot
		 * be ignored) and should  generally stay that way unless you have 
		 * some special need for certain arguments to be ignored.
		 * \param v - Optional Vistor.  You should leave this blank unless
		 * you have a very good reason.
		 */
		UnlabeledValueArg( const std::string& name, 
			               const std::string& desc, 
				           T value,
				           const std::vector<T>& allowed,
						   CmdLine& parser,
						   bool ignoreable = false,
				           Visitor* v = NULL);
						
		/**
		 * Handles the processing of the argument.
		 * This re-implements the Arg version of this method to set the
		 * _value of the argument appropriately.  Handling specific to
		 * unlabled arguments.
		 * \param i - Pointer the the current argument in the list.
		 * \param args - Mutable list of strings. 
		 */
		virtual bool processArg(int* i, std::vector<std::string>& args); 

		/**
		 * Overrides shortID for specific behavior.
		 */
		virtual std::string shortID(const std::string& val="val") const;

		/**
		 * Overrides longID for specific behavior.
		 */
		virtual std::string longID(const std::string& val="val") const;

		/**
		 * Overrides operator== for specific behavior.
		 */
		virtual bool operator==(const Arg& a ) const;

		/**
		 * Instead of pushing to the front of list, push to the back.
		 * \param argList - The list to add this to.
		 */
		virtual void addToList( std::list<Arg*>& argList ) const;
};

/**
 * Constructor implemenation.
 */
template<class T>
UnlabeledValueArg<T>::UnlabeledValueArg(const std::string& name, 
					                    const std::string& desc, 
					                    T val,
					                    const std::string& typeDesc,
					                    bool ignoreable,
					                    Visitor* v)
: ValueArg<T>("", name, desc, true, val, typeDesc, v)
{ 
	_ignoreable = ignoreable;
}

template<class T>
UnlabeledValueArg<T>::UnlabeledValueArg(const std::string& name, 
					                    const std::string& desc, 
					                    T val,
					                    const std::string& typeDesc,
					                    CmdLine& parser,
					                    bool ignoreable,
					                    Visitor* v)
: ValueArg<T>("", name, desc, true, val, typeDesc, v)
{ 
	_ignoreable = ignoreable;
	parser.add( this );
}

/**
 * Constructor implemenation.
 */
template<class T>
UnlabeledValueArg<T>::UnlabeledValueArg(const std::string& name, 
					  const std::string& desc, 
					  T val,
					  const std::vector<T>& allowed,
					  bool ignoreable,
					  Visitor* v)
: ValueArg<T>("", name, desc, true, val, allowed, v)
{ 
	_ignoreable = ignoreable;
}

template<class T>
UnlabeledValueArg<T>::UnlabeledValueArg(const std::string& name, 
					                    const std::string& desc, 
					                    T val,
					                    const std::vector<T>& allowed,
					                    CmdLine& parser,
					                    bool ignoreable,
					                    Visitor* v)
: ValueArg<T>("", name, desc, true, val, allowed,  v)
{ 
	_ignoreable = ignoreable;
	parser.add( this );
}

/**
 * Implementation of processArg().
 */
template<class T>
bool UnlabeledValueArg<T>::processArg(int *i, std::vector<std::string>& args) 
{
	
	if ( _alreadySet )
		return false;
	
	if ( _hasBlanks( args[*i] ) )
		return false;

	// never ignore an unlabeled arg
	
	_extractValue( args[*i] );
	_alreadySet = true;
	return true;
}

/**
 * Overriding shortID for specific output.
 */
template<class T>
std::string UnlabeledValueArg<T>::shortID(const std::string& val) const
{
	std::string id = "<" + _typeDesc + ">";

	return id;
}

/**
 * Overriding longID for specific output.
 */
template<class T>
std::string UnlabeledValueArg<T>::longID(const std::string& val) const
{
	// Ideally we would like to be able to use RTTI to return the name
	// of the type required for this argument.  However, g++ at least, 
	// doesn't appear to return terribly useful "names" of the types.  
	std::string id = "<" + _typeDesc + ">";

	return id;	
}

/**
 * Overriding operator== for specific behavior.
 */
template<class T>
bool UnlabeledValueArg<T>::operator==(const Arg& a ) const
{
	if ( _name == a.getName() || _description == a.getDescription() )
		return true;
	else
		return false;
}

template<class T>
void UnlabeledValueArg<T>::addToList( std::list<Arg*>& argList ) const
{
	argList.push_back( (Arg*)this );
}

}
#endif
