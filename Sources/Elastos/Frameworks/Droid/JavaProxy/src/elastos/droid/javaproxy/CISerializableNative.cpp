
#include "elastos/droid/javaproxy/CISerializableNative.h"
#include <elastos/utility/logging/Logger.h>
#include "elastos/droid/javaproxy/Util.h"

using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace JavaProxy {

const String CISerializableNative::TAG("CISerializableNative");

ECode CISerializableNative::constructor()
{
    return NOERROR;
}

ECode CISerializableNative::constructor(
    /* [in] */ Boolean isDexClassLoader,
    /* [in] */ const String& pkgPath,
    /* [in] */ const String& optimizedDirectory,
    /* [in] */ ArrayOf<Byte>* obj)
{
    mIsDexClassLoader = isDexClassLoader;
    mPkgPath = pkgPath;
    mOptimizedDirectory = optimizedDirectory;
    mObject = obj;
    return NOERROR;
}

ECode CISerializableNative::ReadFromParcel(
    /* [in] */ IParcel* source)
{
    source->ReadBoolean(&mIsDexClassLoader);
    source->ReadString(&mPkgPath);
    source->ReadString(&mOptimizedDirectory);
    source->ReadArrayOf((Handle32*)&mObject);
    return NOERROR;
}

ECode CISerializableNative::WriteToParcel(
    /* [in] */ IParcel* dest)
{
    dest->WriteBoolean(mIsDexClassLoader);
    dest->WriteString(mPkgPath);
    dest->WriteString(mOptimizedDirectory);
    dest->WriteArrayOf((Handle32)mObject.Get());
    return NOERROR;
}

}
}
}
