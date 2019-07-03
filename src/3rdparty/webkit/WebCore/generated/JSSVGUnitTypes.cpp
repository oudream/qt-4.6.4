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

#if ENABLE(SVG)

#include "JSSVGUnitTypes.h"

#include "SVGUnitTypes.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGUnitTypes);

/* Hash table */

static const HashTableValue JSSVGUnitTypesTableValues[2] =
{
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsSVGUnitTypesConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGUnitTypesTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGUnitTypesTableValues, 0 };
#else
    { 2, 1, JSSVGUnitTypesTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGUnitTypesConstructorTableValues[4] =
{
    { "SVG_UNIT_TYPE_UNKNOWN", DontDelete|ReadOnly, (intptr_t)jsSVGUnitTypesSVG_UNIT_TYPE_UNKNOWN, (intptr_t)0 },
    { "SVG_UNIT_TYPE_USERSPACEONUSE", DontDelete|ReadOnly, (intptr_t)jsSVGUnitTypesSVG_UNIT_TYPE_USERSPACEONUSE, (intptr_t)0 },
    { "SVG_UNIT_TYPE_OBJECTBOUNDINGBOX", DontDelete|ReadOnly, (intptr_t)jsSVGUnitTypesSVG_UNIT_TYPE_OBJECTBOUNDINGBOX, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGUnitTypesConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 3, JSSVGUnitTypesConstructorTableValues, 0 };
#else
    { 8, 7, JSSVGUnitTypesConstructorTableValues, 0 };
#endif

class JSSVGUnitTypesConstructor : public DOMConstructorObject {
public:
    JSSVGUnitTypesConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGUnitTypesConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGUnitTypesPrototype::self(exec, globalObject), None);
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

const ClassInfo JSSVGUnitTypesConstructor::s_info = { "SVGUnitTypesConstructor", 0, &JSSVGUnitTypesConstructorTable, 0 };

bool JSSVGUnitTypesConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGUnitTypesConstructor, DOMObject>(exec, &JSSVGUnitTypesConstructorTable, this, propertyName, slot);
}

bool JSSVGUnitTypesConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGUnitTypesConstructor, DOMObject>(exec, &JSSVGUnitTypesConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGUnitTypesPrototypeTableValues[4] =
{
    { "SVG_UNIT_TYPE_UNKNOWN", DontDelete|ReadOnly, (intptr_t)jsSVGUnitTypesSVG_UNIT_TYPE_UNKNOWN, (intptr_t)0 },
    { "SVG_UNIT_TYPE_USERSPACEONUSE", DontDelete|ReadOnly, (intptr_t)jsSVGUnitTypesSVG_UNIT_TYPE_USERSPACEONUSE, (intptr_t)0 },
    { "SVG_UNIT_TYPE_OBJECTBOUNDINGBOX", DontDelete|ReadOnly, (intptr_t)jsSVGUnitTypesSVG_UNIT_TYPE_OBJECTBOUNDINGBOX, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGUnitTypesPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 3, JSSVGUnitTypesPrototypeTableValues, 0 };
#else
    { 8, 7, JSSVGUnitTypesPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGUnitTypesPrototype::s_info = { "SVGUnitTypesPrototype", 0, &JSSVGUnitTypesPrototypeTable, 0 };

JSObject* JSSVGUnitTypesPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGUnitTypes>(exec, globalObject);
}

bool JSSVGUnitTypesPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGUnitTypesPrototype, JSObject>(exec, &JSSVGUnitTypesPrototypeTable, this, propertyName, slot);
}

bool JSSVGUnitTypesPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGUnitTypesPrototype, JSObject>(exec, &JSSVGUnitTypesPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSVGUnitTypes::s_info = { "SVGUnitTypes", 0, &JSSVGUnitTypesTable, 0 };

JSSVGUnitTypes::JSSVGUnitTypes(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGUnitTypes> impl, SVGElement* context)
    : DOMObjectWithSVGContext(structure, globalObject, context)
    , m_impl(impl)
{
}

JSSVGUnitTypes::~JSSVGUnitTypes()
{
    forgetDOMObject(this, impl());
}

JSObject* JSSVGUnitTypes::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGUnitTypesPrototype(JSSVGUnitTypesPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSSVGUnitTypes::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGUnitTypes, Base>(exec, &JSSVGUnitTypesTable, this, propertyName, slot);
}

bool JSSVGUnitTypes::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGUnitTypes, Base>(exec, &JSSVGUnitTypesTable, this, propertyName, descriptor);
}

JSValue jsSVGUnitTypesConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    UNUSED_PARAM(slot);
    return JSSVGUnitTypes::getConstructor(exec, deprecatedGlobalObjectForPrototype(exec));
}
JSValue JSSVGUnitTypes::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGUnitTypesConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

// Constant getters

JSValue jsSVGUnitTypesSVG_UNIT_TYPE_UNKNOWN(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(0));
}

JSValue jsSVGUnitTypesSVG_UNIT_TYPE_USERSPACEONUSE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsSVGUnitTypesSVG_UNIT_TYPE_OBJECTBOUNDINGBOX(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, SVGUnitTypes* object, SVGElement* context)
{
    return getDOMObjectWrapper<JSSVGUnitTypes>(exec, globalObject, object, context);
}
SVGUnitTypes* toSVGUnitTypes(JSC::JSValue value)
{
    return value.inherits(&JSSVGUnitTypes::s_info) ? static_cast<JSSVGUnitTypes*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(SVG)