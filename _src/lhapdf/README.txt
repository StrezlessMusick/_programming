LHAPDF
------------------------------------------
LHAPDF provides a unified and easy to use interface to modern PDF sets. It is
designed to work not only with individual PDF sets but also with the more
recent multiple error sets. It can be viewed as the successor to PDFLIB,
incorporating many of the older sets found in the latter, including pion and
photon PDFs. In LHAPDF the computer code and input parameters/grids are
separated thus allowing more easy updating and no limit to the expansion
possibilities. The code and data sets can be downloaded together or
inidivually as desired. From version 4.1 onwards a configuration script
facilitates the installation of LHAPDF.

Runtime requirements:
  bash-4.1.11-2
  cygwin-1.7.29-2
  libgcc1-4.8.2-3
  libLHAPDF-devel-6.1.0-1bl1
  libLHAPDF0-6.1.0-1bl1
  libstdc++6-4.8.2-3
  python-2.7.5-3

Build requirements:
(besides corresponding -devel packages)
  autoconf-13-1
  automake-9-1
  binutils-2.24.51-2
  boost.m4-0.4-1bl2
  cygport-0.15.0-1
  gcc-core-4.8.2-3
  gcc-g++-4.8.2-3
  libtool-2.4.2-3
  make-4.0-2

Canonical website:
  http://lhapdf.hepforge.org/

Canonical download:
  http://www.hepforge.org/archive/lhapdf/LHAPDF-6.1.0.tar.gz

-------------------------------------------

Build instructions:
  unpack LHAPDF-6.1.0-X-src.tar.xz
    if you use setup to install this src package, it will be
        unpacked under /usr/src automatically
  cd /usr/src
  cygport ./LHAPDF-6.1.0-X.cygport all

This will create:
  /usr/src/LHAPDF-6.1.0-X-src.tar.xz
  /usr/src/LHAPDF-6.1.0-X.tar.xz
  /usr/src/libLHAPDF0-6.1.0-X.tar.xz
  /usr/src/libLHAPDF-devel-6.1.0-X.tar.xz

-------------------------------------------

Files included in the binary package:

(LHAPDF)
  /usr/bin/lhapdf
  /usr/share/LHAPDF/lhapdf.conf
  /usr/share/LHAPDF/pdfsets.index
  /usr/share/doc/Cygwin/LHAPDF.README
  /usr/share/doc/LHAPDF/AUTHORS
  /usr/share/doc/LHAPDF/COPYING
  /usr/share/doc/LHAPDF/ChangeLog
  /usr/share/doc/LHAPDF/README
  /usr/share/doc/LHAPDF/TODO

(libLHAPDF0)
  /usr/bin/cygLHAPDF-0.dll

(libLHAPDF-devel)
  /usr/bin/lhapdf-config
  /usr/include/LHAPDF/AlphaS.h
  /usr/include/LHAPDF/BicubicInterpolator.h
  /usr/include/LHAPDF/BilinearInterpolator.h
  /usr/include/LHAPDF/Config.h
  /usr/include/LHAPDF/ErrExtrapolator.h
  /usr/include/LHAPDF/Exceptions.h
  /usr/include/LHAPDF/Extrapolator.h
  /usr/include/LHAPDF/Factories.h
  /usr/include/LHAPDF/GridPDF.h
  /usr/include/LHAPDF/Info.h
  /usr/include/LHAPDF/Interpolator.h
  /usr/include/LHAPDF/KnotArray.h
  /usr/include/LHAPDF/LHAGlue.h
  /usr/include/LHAPDF/LHAPDF.h
  /usr/include/LHAPDF/LogBicubicInterpolator.h
  /usr/include/LHAPDF/LogBilinearInterpolator.h
  /usr/include/LHAPDF/NearestPointExtrapolator.h
  /usr/include/LHAPDF/PDF.h
  /usr/include/LHAPDF/PDFIndex.h
  /usr/include/LHAPDF/PDFInfo.h
  /usr/include/LHAPDF/PDFSet.h
  /usr/include/LHAPDF/Paths.h
  /usr/include/LHAPDF/Utils.h
  /usr/include/LHAPDF/Version.h
  /usr/lib/libLHAPDF.dll.a
  /usr/lib/pkgconfig/lhapdf.pc

------------------

Port Notes:

----- version 6.1.0-1bl1 -----
Version bump.

----- version 6.0.4-1bl1 -----
Version bump.

----- version 5.8.9-1bl1 -----
Version bump.

----- version 5.8.7-1bl1 -----
Initial release for Cygwin-1.7 by fd0 <http://d.hatena.ne.jp/fd0>
