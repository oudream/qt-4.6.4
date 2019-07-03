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
#include "JSHTMLOListElement.h"

#include "HTMLOListElement.h"
#include "KURL.h"
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLOListElement);

/* Hash table */

static const HashTableValue JSHTMLOListElementTableValues[5] =
{
    { "compact", DontDelete, (intptr_t)jsHTMLOListElementCompact, (intptr_t)setJSHTMLOListElementCompact },
    { "start", DontDelete, (intptr_t)jsHTMLOListElementStart, (intptr_t)setJSHTMLOListElementStart },
    { "type", DontDelete, (intptr_t)jsHTMLOListElementType, (intptr_t)setJSHTMLOListElementType },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsHTMLOListElementConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLOListElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 7, JSHTMLOListElementTableValues, 0 };
#else
    { 8, 7, JSHTMLOListElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSHTMLOListElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLOListElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLOListElementConstructorTableValues, 0 };
#else
    { 1, 0, JSHTMLOListElementConstructorTableValues, 0 };
#endif

class JSHTMLOListElementConstructor : public DOMConstructorObject {
public:
    JSHTMLOListElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSHTMLOListElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSHTMLOListElementPrototype::self(exec, globalObject), None);
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

const ClassInfo JSHTMLOListElementConstructor::s_info = { "HTMLOListElementConstructor", 0, &JSHTMLOListElementConstructorTable, 0 };

bool JSHTMLOListElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLOListElementConstructor, DOMObject>(exec, &JSHTMLOListElementConstructorTable, this, propertyName, slot);
}

bool JSHTMLOListElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLOListElementConstructor, DOMObject>(exec, &JSHTMLOListElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLOListElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLOListElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLOListElementPrototypeTableValues, 0 };
#else
    { 1, 0, JSHTMLOListElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSHTMLOListElementPrototype::s_info = { "HTMLOListElementPrototype", 0, &JSHTMLOListElementPrototypeTable, 0 };

JSObject* JSHTMLOListElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLOListElement>(exec, globalObject);
}

const ClassInfo JSHTMLOListElement::s_info = { "HTMLOListElement", &JSHTMLElement::s_info, &JSHTMLOListElementTable, 0 };

JSHTMLOListElement::JSHTMLOListElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLOListElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

JSObject* JSHTMLOListElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLOListElementPrototype(JSHTMLOListElementPrototype::createStructure(JSHTMLElementPrototype::self(exec, globalObject)));
}

bool JSHTMLOListElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLOListElement, Base>(exec, &JSHTMLOListElementTable, this, propertyName, slot);
}

bool JSHTMLOListElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLOListElement, Base>(exec, &JSHTMLOListElementTable, this, propertyName, descriptor);
}

JSValue jsHTMLOListElementCompact(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLOListElement* castedThis = static_cast<JSHTMLOListElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLOListElement* imp = static_cast<HTMLOListElement*>(castedThis->impl());
    return jsBoolean(imp->compact());
}

JSValue jsHTMLOListElementStart(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLOListElement* castedThis = static_cast<JSHTMLOListElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLOListElement* imp = static_cast<HTMLOListElement*>(castedThis->impl());
    return jsNumber(exec, imp->start());
}

JSValue jsHTMLOListElementType(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLOListElement* castedThis = static_cast<JSHTMLOListElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLOListElement* imp = static_cast<HTMLOListElement*>(castedThis->impl());
    return jsString(exec, imp->type());
}

JSValue jsHTMLOListElementConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLOListElement* domObject = static_cast<JSHTMLOListElement*>(asObject(slot.slotBase()));
    return JSHTMLOListElement::getConstructor(exec, domObject->globalObject());
}
void JSHTMLOListElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSHTMLOListElement, Base>(exec, propertyName, value, &JSHTMLOListElementTable, this, slot);
}

void setJSHTMLOListElementCompact(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLOListElement* imp = static_cast<HTMLOListElement*>(static_cast<JSHTMLOListElement*>(thisObject)->impl());
    imp->setCompact(value.toBoolean(exec));
}

void setJSHTMLOListElementStart(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLOListElement* imp = static_cast<HTMLOListElement*>(static_cast<JSHTMLOListElement*>(thisObject)->impl());
    imp->setStart(value.toInt32(exec));
}

void setJSHTMLOListElementType(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLOListElement* imp = static_cast<HTMLOListElement*>(static_cast<JSHTMLOListElement*>(thisObject)->impl());
    imp->setType(valueToStringWithNullCheck(exec, value));
}

JSValue JSHTMLOListElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLOListElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}
