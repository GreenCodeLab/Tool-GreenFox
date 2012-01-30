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
#define NS_ISAMPLE_IID_STR "03a6d0b4-22b9-11df-b844-20d556d89593"

#define NS_ISAMPLE_IID \
  {0x03a6d0b4, 0x22b9, 0x11df, \
    { 0xb8, 0x44, 0x20, 0xd5, 0x56, 0xd8, 0x95, 0x93 }}

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

  /* void start (); */
  NS_SCRIPTABLE NS_IMETHOD Start(void) = 0;

  /* double stop (); */
  NS_SCRIPTABLE NS_IMETHOD Stop(double *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISample, NS_ISAMPLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAMPLE \
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const char * aValue); \
  NS_SCRIPTABLE NS_IMETHOD WriteValue(const char * aPrefix); \
  NS_SCRIPTABLE NS_IMETHOD Poke(const char * aValue); \
  NS_SCRIPTABLE NS_IMETHOD Start(void); \
  NS_SCRIPTABLE NS_IMETHOD Stop(double *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAMPLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const char * aValue) { return _to SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD WriteValue(const char * aPrefix) { return _to WriteValue(aPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD Poke(const char * aValue) { return _to Poke(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD Start(void) { return _to Start(); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(double *_retval NS_OUTPARAM) { return _to Stop(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAMPLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(char * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const char * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD WriteValue(const char * aPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteValue(aPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD Poke(const char * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->Poke(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD Start(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(_retval); } 

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

/* void start (); */
NS_IMETHODIMP nsSample::Start()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double stop (); */
NS_IMETHODIMP nsSample::Stop(double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISample_h__ */
