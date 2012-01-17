/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM nsISample.idl
 */

#ifndef __gen_nsISample_h__
#define __gen_nsISample_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISample */
#define NS_ISAMPLE_IID_STR "7cb5b7a1-07d7-11d3-bde2-000064657374"

#define NS_ISAMPLE_IID \
  {0x7cb5b7a1, 0x07d7, 0x11d3, \
    { 0xbd, 0xe2, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISample : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAMPLE_IID)

  /* attribute string value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(const char * aValue) = 0;

  /* void writeValue (in string aPrefix); */
  NS_SCRIPTABLE NS_IMETHOD WriteValue(const char * aPrefix) = 0;

  /* void poke (in string aValue); */
  NS_SCRIPTABLE NS_IMETHOD Poke(const char * aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISample, NS_ISAMPLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAMPLE \
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const char * aValue); \
  NS_SCRIPTABLE NS_IMETHOD WriteValue(const char * aPrefix); \
  NS_SCRIPTABLE NS_IMETHOD Poke(const char * aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAMPLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const char * aValue) { return _to SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD WriteValue(const char * aPrefix) { return _to WriteValue(aPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD Poke(const char * aValue) { return _to Poke(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAMPLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const char * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD WriteValue(const char * aPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteValue(aPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD Poke(const char * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->Poke(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSample : public nsISample
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAMPLE

  nsSample();

private:
  ~nsSample();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSample, nsISample)

nsSample::nsSample()
{
  /* member initializers and constructor code */
}

nsSample::~nsSample()
{
  /* destructor code */
}

/* attribute string value; */
NS_IMETHODIMP nsSample::GetValue(char * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSample::SetValue(const char * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeValue (in string aPrefix); */
NS_IMETHODIMP nsSample::WriteValue(const char * aPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void poke (in string aValue); */
NS_IMETHODIMP nsSample::Poke(const char * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISample_h__ */
