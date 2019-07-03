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
#include "JSWebKitCSSTransformValue.h"

#include "WebKitCSSTransformValue.h"
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSWebKitCSSTransformValue);

/* Hash table */

static const HashTableValue JSWebKitCSSTransformValueTableValues[3] =
{
    { "operationType", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueOperationType, (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsWebKitCSSTransformValueConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWebKitCSSTransformValueTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSWebKitCSSTransformValueTableValues, 0 };
#else
    { 5, 3, JSWebKitCSSTransformValueTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSWebKitCSSTransformValueConstructorTableValues[22] =
{
    { "CSS_TRANSLATE", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATE, (intptr_t)0 },
    { "CSS_TRANSLATEX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATEX, (intptr_t)0 },
    { "CSS_TRANSLATEY", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATEY, (intptr_t)0 },
    { "CSS_ROTATE", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATE, (intptr_t)0 },
    { "CSS_SCALE", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALE, (intptr_t)0 },
    { "CSS_SCALEX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALEX, (intptr_t)0 },
    { "CSS_SCALEY", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALEY, (intptr_t)0 },
    { "CSS_SKEW", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SKEW, (intptr_t)0 },
    { "CSS_SKEWX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SKEWX, (intptr_t)0 },
    { "CSS_SKEWY", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SKEWY, (intptr_t)0 },
    { "CSS_MATRIX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_MATRIX, (intptr_t)0 },
    { "CSS_TRANSLATEZ", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATEZ, (intptr_t)0 },
    { "CSS_TRANSLATE3D", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATE3D, (intptr_t)0 },
    { "CSS_ROTATEX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATEX, (intptr_t)0 },
    { "CSS_ROTATEY", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATEY, (intptr_t)0 },
    { "CSS_ROTATEZ", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATEZ, (intptr_t)0 },
    { "CSS_ROTATE3D", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATE3D, (intptr_t)0 },
    { "CSS_SCALEZ", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALEZ, (intptr_t)0 },
    { "CSS_SCALE3D", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALE3D, (intptr_t)0 },
    { "CSS_PERSPECTIVE", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_PERSPECTIVE, (intptr_t)0 },
    { "CSS_MATRIX3D", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_MATRIX3D, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWebKitCSSTransformValueConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1023, JSWebKitCSSTransformValueConstructorTableValues, 0 };
#else
    { 68, 63, JSWebKitCSSTransformValueConstructorTableValues, 0 };
#endif

class JSWebKitCSSTransformValueConstructor : public DOMConstructorObject {
public:
    JSWebKitCSSTransformValueConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSWebKitCSSTransformValueConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSWebKitCSSTransformValuePrototype::self(exec, globalObject), None);
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

const ClassInfo JSWebKitCSSTransformValueConstructor::s_info = { "WebKitCSSTransformValueConstructor", 0, &JSWebKitCSSTransformValueConstructorTable, 0 };

bool JSWebKitCSSTransformValueConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSWebKitCSSTransformValueConstructor, DOMObject>(exec, &JSWebKitCSSTransformValueConstructorTable, this, propertyName, slot);
}

bool JSWebKitCSSTransformValueConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSWebKitCSSTransformValueConstructor, DOMObject>(exec, &JSWebKitCSSTransformValueConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSWebKitCSSTransformValuePrototypeTableValues[22] =
{
    { "CSS_TRANSLATE", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATE, (intptr_t)0 },
    { "CSS_TRANSLATEX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATEX, (intptr_t)0 },
    { "CSS_TRANSLATEY", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATEY, (intptr_t)0 },
    { "CSS_ROTATE", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATE, (intptr_t)0 },
    { "CSS_SCALE", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALE, (intptr_t)0 },
    { "CSS_SCALEX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALEX, (intptr_t)0 },
    { "CSS_SCALEY", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALEY, (intptr_t)0 },
    { "CSS_SKEW", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SKEW, (intptr_t)0 },
    { "CSS_SKEWX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SKEWX, (intptr_t)0 },
    { "CSS_SKEWY", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SKEWY, (intptr_t)0 },
    { "CSS_MATRIX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_MATRIX, (intptr_t)0 },
    { "CSS_TRANSLATEZ", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATEZ, (intptr_t)0 },
    { "CSS_TRANSLATE3D", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_TRANSLATE3D, (intptr_t)0 },
    { "CSS_ROTATEX", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATEX, (intptr_t)0 },
    { "CSS_ROTATEY", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATEY, (intptr_t)0 },
    { "CSS_ROTATEZ", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATEZ, (intptr_t)0 },
    { "CSS_ROTATE3D", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_ROTATE3D, (intptr_t)0 },
    { "CSS_SCALEZ", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALEZ, (intptr_t)0 },
    { "CSS_SCALE3D", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_SCALE3D, (intptr_t)0 },
    { "CSS_PERSPECTIVE", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_PERSPECTIVE, (intptr_t)0 },
    { "CSS_MATRIX3D", DontDelete|ReadOnly, (intptr_t)jsWebKitCSSTransformValueCSS_MATRIX3D, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWebKitCSSTransformValuePrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1023, JSWebKitCSSTransformValuePrototypeTableValues, 0 };
#else
    { 68, 63, JSWebKitCSSTransformValuePrototypeTableValues, 0 };
#endif

const ClassInfo JSWebKitCSSTransformValuePrototype::s_info = { "WebKitCSSTransformValuePrototype", 0, &JSWebKitCSSTransformValuePrototypeTable, 0 };

JSObject* JSWebKitCSSTransformValuePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSWebKitCSSTransformValue>(exec, globalObject);
}

bool JSWebKitCSSTransformValuePrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSWebKitCSSTransformValuePrototype, JSObject>(exec, &JSWebKitCSSTransformValuePrototypeTable, this, propertyName, slot);
}

bool JSWebKitCSSTransformValuePrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSWebKitCSSTransformValuePrototype, JSObject>(exec, &JSWebKitCSSTransformValuePrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSWebKitCSSTransformValue::s_info = { "WebKitCSSTransformValue", &JSCSSValueList::s_info, &JSWebKitCSSTransformValueTable, 0 };

JSWebKitCSSTransformValue::JSWebKitCSSTransformValue(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<WebKitCSSTransformValue> impl)
    : JSCSSValueList(structure, globalObject, impl)
{
}

JSObject* JSWebKitCSSTransformValue::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSWebKitCSSTransformValuePrototype(JSWebKitCSSTransformValuePrototype::createStructure(JSCSSValueListPrototype::self(exec, globalObject)));
}

bool JSWebKitCSSTransformValue::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSWebKitCSSTransformValue, Base>(exec, &JSWebKitCSSTransformValueTable, this, propertyName, slot);
}

bool JSWebKitCSSTransformValue::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSWebKitCSSTransformValue, Base>(exec, &JSWebKitCSSTransformValueTable, this, propertyName, descriptor);
}

JSValue jsWebKitCSSTransformValueOperationType(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWebKitCSSTransformValue* castedThis = static_cast<JSWebKitCSSTransformValue*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    WebKitCSSTransformValue* imp = static_cast<WebKitCSSTransformValue*>(castedThis->impl());
    return jsNumber(exec, imp->operationType());
}

JSValue jsWebKitCSSTransformValueConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSWebKitCSSTransformValue* domObject = static_cast<JSWebKitCSSTransformValue*>(asObject(slot.slotBase()));
    return JSWebKitCSSTransformValue::getConstructor(exec, domObject->globalObject());
}
JSValue JSWebKitCSSTransformValue::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSWebKitCSSTransformValueConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

// Constant getters

JSValue jsWebKitCSSTransformValueCSS_TRANSLATE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsWebKitCSSTransformValueCSS_TRANSLATEX(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSValue jsWebKitCSSTransformValueCSS_TRANSLATEY(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(3));
}

JSValue jsWebKitCSSTransformValueCSS_ROTATE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(4));
}

JSValue jsWebKitCSSTransformValueCSS_SCALE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(5));
}

JSValue jsWebKitCSSTransformValueCSS_SCALEX(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(6));
}

JSValue jsWebKitCSSTransformValueCSS_SCALEY(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(7));
}

JSValue jsWebKitCSSTransformValueCSS_SKEW(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(8));
}

JSValue jsWebKitCSSTransformValueCSS_SKEWX(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(9));
}

JSValue jsWebKitCSSTransformValueCSS_SKEWY(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(10));
}

JSValue jsWebKitCSSTransformValueCSS_MATRIX(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(11));
}

JSValue jsWebKitCSSTransformValueCSS_TRANSLATEZ(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(12));
}

JSValue jsWebKitCSSTransformValueCSS_TRANSLATE3D(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(13));
}

JSValue jsWebKitCSSTransformValueCSS_ROTATEX(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(14));
}

JSValue jsWebKitCSSTransformValueCSS_ROTATEY(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(15));
}

JSValue jsWebKitCSSTransformValueCSS_ROTATEZ(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(16));
}

JSValue jsWebKitCSSTransformValueCSS_ROTATE3D(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(17));
}

JSValue jsWebKitCSSTransformValueCSS_SCALEZ(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(18));
}

JSValue jsWebKitCSSTransformValueCSS_SCALE3D(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(19));
}

JSValue jsWebKitCSSTransformValueCSS_PERSPECTIVE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(20));
}

JSValue jsWebKitCSSTransformValueCSS_MATRIX3D(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(21));
}


}
