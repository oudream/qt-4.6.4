/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSHTMLInputElement.h"

#include "FileList.h"
#include "HTMLFormElement.h"
#include "HTMLInputElement.h"
#include "HTMLNames.h"
#include "JSFileList.h"
#include "JSHTMLFormElement.h"
#include "JSValidityState.h"
#include "KURL.h"
#include "ValidityState.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLInputElement);

/* Hash table */

static const HashTableValue JSHTMLInputElementTableValues[33] =
{
    { "defaultValue", DontDelete, (intptr_t)jsHTMLInputElementDefaultValue, (intptr_t)setJSHTMLInputElementDefaultValue },
    { "defaultChecked", DontDelete, (intptr_t)jsHTMLInputElementDefaultChecked, (intptr_t)setJSHTMLInputElementDefaultChecked },
    { "form", DontDelete|ReadOnly, (intptr_t)jsHTMLInputElementForm, (intptr_t)0 },
    { "formNoValidate", DontDelete, (intptr_t)jsHTMLInputElementFormNoValidate, (intptr_t)setJSHTMLInputElementFormNoValidate },
    { "validity", DontDelete|ReadOnly, (intptr_t)jsHTMLInputElementValidity, (intptr_t)0 },
    { "accept", DontDelete, (intptr_t)jsHTMLInputElementAccept, (intptr_t)setJSHTMLInputElementAccept },
    { "accessKey", DontDelete, (intptr_t)jsHTMLInputElementAccessKey, (intptr_t)setJSHTMLInputElementAccessKey },
    { "align", DontDelete, (intptr_t)jsHTMLInputElementAlign, (intptr_t)setJSHTMLInputElementAlign },
    { "alt", DontDelete, (intptr_t)jsHTMLInputElementAlt, (intptr_t)setJSHTMLInputElementAlt },
    { "checked", DontDelete, (intptr_t)jsHTMLInputElementChecked, (intptr_t)setJSHTMLInputElementChecked },
    { "disabled", DontDelete, (intptr_t)jsHTMLInputElementDisabled, (intptr_t)setJSHTMLInputElementDisabled },
    { "autofocus", DontDelete, (intptr_t)jsHTMLInputElementAutofocus, (intptr_t)setJSHTMLInputElementAutofocus },
    { "max", DontDelete, (intptr_t)jsHTMLInputElementMax, (intptr_t)setJSHTMLInputElementMax },
    { "maxLength", DontDelete, (intptr_t)jsHTMLInputElementMaxLength, (intptr_t)setJSHTMLInputElementMaxLength },
    { "min", DontDelete, (intptr_t)jsHTMLInputElementMin, (intptr_t)setJSHTMLInputElementMin },
    { "multiple", DontDelete, (intptr_t)jsHTMLInputElementMultiple, (intptr_t)setJSHTMLInputElementMultiple },
    { "name", DontDelete, (intptr_t)jsHTMLInputElementName, (intptr_t)setJSHTMLInputElementName },
    { "pattern", DontDelete, (intptr_t)jsHTMLInputElementPattern, (intptr_t)setJSHTMLInputElementPattern },
    { "placeholder", DontDelete, (intptr_t)jsHTMLInputElementPlaceholder, (intptr_t)setJSHTMLInputElementPlaceholder },
    { "readOnly", DontDelete, (intptr_t)jsHTMLInputElementReadOnly, (intptr_t)setJSHTMLInputElementReadOnly },
    { "required", DontDelete, (intptr_t)jsHTMLInputElementRequired, (intptr_t)setJSHTMLInputElementRequired },
    { "size", DontDelete, (intptr_t)jsHTMLInputElementSize, (intptr_t)setJSHTMLInputElementSize },
    { "src", DontDelete, (intptr_t)jsHTMLInputElementSrc, (intptr_t)setJSHTMLInputElementSrc },
    { "type", DontDelete, (intptr_t)jsHTMLInputElementType, (intptr_t)setJSHTMLInputElementType },
    { "useMap", DontDelete, (intptr_t)jsHTMLInputElementUseMap, (intptr_t)setJSHTMLInputElementUseMap },
    { "value", DontDelete, (intptr_t)jsHTMLInputElementValue, (intptr_t)setJSHTMLInputElementValue },
    { "willValidate", DontDelete|ReadOnly, (intptr_t)jsHTMLInputElementWillValidate, (intptr_t)0 },
    { "indeterminate", DontDelete, (intptr_t)jsHTMLInputElementIndeterminate, (intptr_t)setJSHTMLInputElementIndeterminate },
    { "selectionStart", DontDelete, (intptr_t)jsHTMLInputElementSelectionStart, (intptr_t)setJSHTMLInputElementSelectionStart },
    { "selectionEnd", DontDelete, (intptr_t)jsHTMLInputElementSelectionEnd, (intptr_t)setJSHTMLInputElementSelectionEnd },
    { "files", DontDelete|ReadOnly, (intptr_t)jsHTMLInputElementFiles, (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsHTMLInputElementConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLInputElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 2047, JSHTMLInputElementTableValues, 0 };
#else
    { 73, 63, JSHTMLInputElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSHTMLInputElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLInputElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLInputElementConstructorTableValues, 0 };
#else
    { 1, 0, JSHTMLInputElementConstructorTableValues, 0 };
#endif

class JSHTMLInputElementConstructor : public DOMConstructorObject {
public:
    JSHTMLInputElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSHTMLInputElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSHTMLInputElementPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags)); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSHTMLInputElementConstructor::s_info = { "HTMLInputElementConstructor", 0, &JSHTMLInputElementConstructorTable, 0 };

bool JSHTMLInputElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLInputElementConstructor, DOMObject>(exec, &JSHTMLInputElementConstructorTable, this, propertyName, slot);
}

bool JSHTMLInputElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLInputElementConstructor, DOMObject>(exec, &JSHTMLInputElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLInputElementPrototypeTableValues[6] =
{
    { "checkValidity", DontDelete|Function, (intptr_t)jsHTMLInputElementPrototypeFunctionCheckValidity, (intptr_t)0 },
    { "setCustomValidity", DontDelete|Function, (intptr_t)jsHTMLInputElementPrototypeFunctionSetCustomValidity, (intptr_t)1 },
    { "select", DontDelete|Function, (intptr_t)jsHTMLInputElementPrototypeFunctionSelect, (intptr_t)0 },
    { "click", DontDelete|Function, (intptr_t)jsHTMLInputElementPrototypeFunctionClick, (intptr_t)0 },
    { "setSelectionRange", DontDelete|Function, (intptr_t)jsHTMLInputElementPrototypeFunctionSetSelectionRange, (intptr_t)2 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLInputElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSHTMLInputElementPrototypeTableValues, 0 };
#else
    { 16, 15, JSHTMLInputElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSHTMLInputElementPrototype::s_info = { "HTMLInputElementPrototype", 0, &JSHTMLInputElementPrototypeTable, 0 };

JSObject* JSHTMLInputElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLInputElement>(exec, globalObject);
}

bool JSHTMLInputElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSHTMLInputElementPrototypeTable, this, propertyName, slot);
}

bool JSHTMLInputElementPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSHTMLInputElementPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSHTMLInputElement::s_info = { "HTMLInputElement", &JSHTMLElement::s_info, &JSHTMLInputElementTable, 0 };

JSHTMLInputElement::JSHTMLInputElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLInputElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

JSObject* JSHTMLInputElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLInputElementPrototype(JSHTMLInputElementPrototype::createStructure(JSHTMLElementPrototype::self(exec, globalObject)));
}

bool JSHTMLInputElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLInputElement, Base>(exec, &JSHTMLInputElementTable, this, propertyName, slot);
}

bool JSHTMLInputElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLInputElement, Base>(exec, &JSHTMLInputElementTable, this, propertyName, descriptor);
}

JSValue jsHTMLInputElementDefaultValue(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->defaultValue());
}

JSValue jsHTMLInputElementDefaultChecked(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->defaultChecked());
}

JSValue jsHTMLInputElementForm(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->form()));
}

JSValue jsHTMLInputElementFormNoValidate(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->formNoValidate());
}

JSValue jsHTMLInputElementValidity(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->validity()));
}

JSValue jsHTMLInputElementAccept(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->accept());
}

JSValue jsHTMLInputElementAccessKey(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->accessKey());
}

JSValue jsHTMLInputElementAlign(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->align());
}

JSValue jsHTMLInputElementAlt(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->alt());
}

JSValue jsHTMLInputElementChecked(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->checked());
}

JSValue jsHTMLInputElementDisabled(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->disabled());
}

JSValue jsHTMLInputElementAutofocus(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->autofocus());
}

JSValue jsHTMLInputElementMax(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->getAttribute(HTMLNames::maxAttr));
}

JSValue jsHTMLInputElementMaxLength(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsNumber(exec, imp->maxLength());
}

JSValue jsHTMLInputElementMin(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->getAttribute(HTMLNames::minAttr));
}

JSValue jsHTMLInputElementMultiple(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->multiple());
}

JSValue jsHTMLInputElementName(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->name());
}

JSValue jsHTMLInputElementPattern(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->getAttribute(HTMLNames::patternAttr));
}

JSValue jsHTMLInputElementPlaceholder(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->placeholder());
}

JSValue jsHTMLInputElementReadOnly(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->readOnly());
}

JSValue jsHTMLInputElementRequired(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->required());
}

JSValue jsHTMLInputElementSize(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsNumber(exec, imp->size());
}

JSValue jsHTMLInputElementSrc(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->src());
}

JSValue jsHTMLInputElementType(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    return castedThis->type(exec);
}

JSValue jsHTMLInputElementUseMap(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->useMap());
}

JSValue jsHTMLInputElementValue(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsString(exec, imp->value());
}

JSValue jsHTMLInputElementWillValidate(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->willValidate());
}

JSValue jsHTMLInputElementIndeterminate(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return jsBoolean(imp->indeterminate());
}

JSValue jsHTMLInputElementSelectionStart(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    return castedThis->selectionStart(exec);
}

JSValue jsHTMLInputElementSelectionEnd(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    return castedThis->selectionEnd(exec);
}

JSValue jsHTMLInputElementFiles(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* castedThis = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->files()));
}

JSValue jsHTMLInputElementConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLInputElement* domObject = static_cast<JSHTMLInputElement*>(asObject(slot.slotBase()));
    return JSHTMLInputElement::getConstructor(exec, domObject->globalObject());
}
void JSHTMLInputElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSHTMLInputElement, Base>(exec, propertyName, value, &JSHTMLInputElementTable, this, slot);
}

void setJSHTMLInputElementDefaultValue(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setDefaultValue(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementDefaultChecked(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setDefaultChecked(value.toBoolean(exec));
}

void setJSHTMLInputElementFormNoValidate(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setFormNoValidate(value.toBoolean(exec));
}

void setJSHTMLInputElementAccept(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setAccept(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementAccessKey(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setAccessKey(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementAlign(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setAlign(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementAlt(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setAlt(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementChecked(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setChecked(value.toBoolean(exec));
}

void setJSHTMLInputElementDisabled(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setDisabled(value.toBoolean(exec));
}

void setJSHTMLInputElementAutofocus(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setAutofocus(value.toBoolean(exec));
}

void setJSHTMLInputElementMax(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setAttribute(HTMLNames::maxAttr, value.toString(exec));
}

void setJSHTMLInputElementMaxLength(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    ExceptionCode ec = 0;
    imp->setMaxLength(value.toInt32(exec), ec);
    setDOMException(exec, ec);
}

void setJSHTMLInputElementMin(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setAttribute(HTMLNames::minAttr, value.toString(exec));
}

void setJSHTMLInputElementMultiple(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setMultiple(value.toBoolean(exec));
}

void setJSHTMLInputElementName(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setName(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementPattern(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setAttribute(HTMLNames::patternAttr, value.toString(exec));
}

void setJSHTMLInputElementPlaceholder(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setPlaceholder(value.toString(exec));
}

void setJSHTMLInputElementReadOnly(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setReadOnly(value.toBoolean(exec));
}

void setJSHTMLInputElementRequired(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setRequired(value.toBoolean(exec));
}

void setJSHTMLInputElementSize(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setSize(value.toInt32(exec));
}

void setJSHTMLInputElementSrc(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setSrc(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementType(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setType(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementUseMap(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setUseMap(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementValue(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setValue(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLInputElementIndeterminate(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(static_cast<JSHTMLInputElement*>(thisObject)->impl());
    imp->setIndeterminate(value.toBoolean(exec));
}

void setJSHTMLInputElementSelectionStart(ExecState* exec, JSObject* thisObject, JSValue value)
{
    static_cast<JSHTMLInputElement*>(thisObject)->setSelectionStart(exec, value);
}

void setJSHTMLInputElementSelectionEnd(ExecState* exec, JSObject* thisObject, JSValue value)
{
    static_cast<JSHTMLInputElement*>(thisObject)->setSelectionEnd(exec, value);
}

JSValue JSHTMLInputElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLInputElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsHTMLInputElementPrototypeFunctionCheckValidity(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSHTMLInputElement::s_info))
        return throwError(exec, TypeError);
    JSHTMLInputElement* castedThisObj = static_cast<JSHTMLInputElement*>(asObject(thisValue));
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThisObj->impl());


    JSC::JSValue result = jsBoolean(imp->checkValidity());
    return result;
}

JSValue JSC_HOST_CALL jsHTMLInputElementPrototypeFunctionSetCustomValidity(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSHTMLInputElement::s_info))
        return throwError(exec, TypeError);
    JSHTMLInputElement* castedThisObj = static_cast<JSHTMLInputElement*>(asObject(thisValue));
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThisObj->impl());
    const UString& error = valueToStringWithUndefinedOrNullCheck(exec, args.at(0));

    imp->setCustomValidity(error);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsHTMLInputElementPrototypeFunctionSelect(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSHTMLInputElement::s_info))
        return throwError(exec, TypeError);
    JSHTMLInputElement* castedThisObj = static_cast<JSHTMLInputElement*>(asObject(thisValue));
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThisObj->impl());

    imp->select();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsHTMLInputElementPrototypeFunctionClick(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSHTMLInputElement::s_info))
        return throwError(exec, TypeError);
    JSHTMLInputElement* castedThisObj = static_cast<JSHTMLInputElement*>(asObject(thisValue));
    HTMLInputElement* imp = static_cast<HTMLInputElement*>(castedThisObj->impl());

    imp->click();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsHTMLInputElementPrototypeFunctionSetSelectionRange(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSHTMLInputElement::s_info))
        return throwError(exec, TypeError);
    JSHTMLInputElement* castedThisObj = static_cast<JSHTMLInputElement*>(asObject(thisValue));
    return castedThisObj->setSelectionRange(exec, args);
}


}