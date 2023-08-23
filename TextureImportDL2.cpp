// TextureImportDL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <TlHelp32.h>
#include <vector>
#include <stdlib.h>
#include <winternl.h>
#include <set>
#include <stdlib.h>
#include <intrin.h>

void Unpack()
{
    std::ifstream is;
    std::ofstream os;
    is.open("common_textures_0_pc.rpack", std::ios::binary);
    DWORD magicID;
    is.read(reinterpret_cast<char*>(&magicID), sizeof(magicID));
    DWORD space1;
    is.read(reinterpret_cast<char*>(&space1), sizeof(space1));
    DWORD space2;
    is.read(reinterpret_cast<char*>(&space2), sizeof(space2));
    int Parts;
    is.read(reinterpret_cast<char*>(&Parts), sizeof(Parts));
    int Sections;
    is.read(reinterpret_cast<char*>(&Sections), sizeof(Sections));
    int Files;
    is.read(reinterpret_cast<char*>(&Files), sizeof(Files));
    int Fnames_Size;
    is.read(reinterpret_cast<char*>(&Fnames_Size), sizeof(Fnames_Size));
    int Fnames;
    is.read(reinterpret_cast<char*>(&Fnames), sizeof(Fnames));
    DWORD space3;
    is.read(reinterpret_cast<char*>(&space3), sizeof(space3));
    DWORD HeaderSectionStart;
    is.read(reinterpret_cast<char*>(&HeaderSectionStart), sizeof(HeaderSectionStart));
    int HeaderSectionOffset;
    is.read(reinterpret_cast<char*>(&HeaderSectionOffset), sizeof(HeaderSectionOffset));
    int HeaderSectionUnpackedSize;
    is.read(reinterpret_cast<char*>(&HeaderSectionUnpackedSize), sizeof(HeaderSectionUnpackedSize));
    int HeaderSectionPackedSize;
    is.read(reinterpret_cast<char*>(&HeaderSectionPackedSize), sizeof(HeaderSectionPackedSize));
    DWORD HeaderSectionSpace1;
    is.read(reinterpret_cast<char*>(&HeaderSectionSpace1), sizeof(HeaderSectionSpace1));
    DWORD BodySectionStart;
    is.read(reinterpret_cast<char*>(&BodySectionStart), sizeof(BodySectionStart));
    int BodySectionOffset;
    is.read(reinterpret_cast<char*>(&BodySectionOffset), sizeof(BodySectionOffset));
    int BodySectionUnpackedSize;
    is.read(reinterpret_cast<char*>(&BodySectionUnpackedSize), sizeof(BodySectionUnpackedSize));
    int BodySectionPackedSize;
    is.read(reinterpret_cast<char*>(&BodySectionPackedSize), sizeof(BodySectionPackedSize));
    DWORD BodySectionSpace1;
    is.read(reinterpret_cast<char*>(&BodySectionSpace1), sizeof(BodySectionSpace1));
    SHORT Filetype;
    SHORT Partindex;
    int RelativeOffset;
    int Filesize;
    int Unk;
    SHORT Filetype2;
    SHORT Partindex2;
    int RelativeOffset2;
    int Filesize2;
    int Unk2;
    int Tell1 = 0;
    int Tell2 = 0;
    int Tell3 = 0;
    int offsetfnames;
    int fnamesstart = 36 + 20 * Sections + 16 * Parts + Files * 12;
    BYTE fnamesbyte;
    SHORT width;
    SHORT height;
    SHORT depth;
    BYTE buf;
    BYTE fill1[0xc] = { 0x44, 0x44, 0x53, 0x20, 0x7C, 0x00, 0x00, 0x00, 0x07, 0x10, 0x0A, 0x00 };
    BYTE fill1a[0x4] = { 00, 00, 0x08, 00, };
    BYTE fill2[0x66] = { 0,0,0x01, 00, 00, 00, 00, 00, 00, 00, 00, 00,
        00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00,
        00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 0x20, 00, 00, 00, 0x04, 00, 00, 0x00, 0x44,
        0x58, 0x54, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 ,0x00 ,0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    BYTE fill3[2] = { 0,0 };

    for (int i = 0; i < Files; i++)
    {
        if (i > 0)
        {
            is.seekg(Tell3, std::ios::beg);
        }
        else
        {
            is.seekg(fnamesstart, std::ios::beg);
        }
        is.read(reinterpret_cast<char*>(&offsetfnames), sizeof(offsetfnames));
        Tell3 = is.tellg();
        is.seekg(0x1996FC, std::ios::beg);
        is.seekg(offsetfnames, SEEK_CUR);
        while (1)
        {
            is.read(reinterpret_cast<char*>(&fnamesbyte), sizeof(fnamesbyte));
            if (fnamesbyte == 0)
            {
                break;
            }
            
            std::cout << fnamesbyte;
        }
        std::cout << "           " + std::to_string(i);
        std::cout << std::endl;
    }
    is.seekg(0x4C, std::ios::beg);
    std::cout << "Input number to unpack." << std::endl;
    int numinp1;
    std::cin >> numinp1;
    for (int i = 0; i < numinp1; i++)
    {
       
        
        is.read(reinterpret_cast<char*>(&Filetype), sizeof(Filetype));
        is.read(reinterpret_cast<char*>(&Partindex), sizeof(Partindex));
        is.read(reinterpret_cast<char*>(&RelativeOffset), sizeof(RelativeOffset));
        is.read(reinterpret_cast<char*>(&Filesize), sizeof(Filesize));
        is.read(reinterpret_cast<char*>(&Unk), sizeof(Unk));
        is.read(reinterpret_cast<char*>(&Filetype2), sizeof(Filetype2));
        is.read(reinterpret_cast<char*>(&Partindex2), sizeof(Partindex2));
        is.read(reinterpret_cast<char*>(&RelativeOffset2), sizeof(RelativeOffset2));
        is.read(reinterpret_cast<char*>(&Filesize2), sizeof(Filesize2));
        is.read(reinterpret_cast<char*>(&Unk2), sizeof(Unk2));
        Tell1 = is.tellg();
        if (i > 0)
        {
            is.seekg(Tell2, std::ios::beg);
        }
        else
        {
            is.seekg(HeaderSectionOffset * 0x10, std::ios::beg);
        }
        is.seekg(0x40, SEEK_CUR);
        is.read(reinterpret_cast<char*>(&width), sizeof(width));
        is.read(reinterpret_cast<char*>(&height), sizeof(height));
        is.read(reinterpret_cast<char*>(&depth), sizeof(depth));
        is.seekg(0xA, SEEK_CUR);
        Tell2 = is.tellg();
        is.seekg(BodySectionOffset + RelativeOffset, std::ios::beg);
        is.seekg(Filesize, SEEK_CUR);
        is.seekg(Tell1, std::ios::beg);
    }
    os.open("extraction.dds", std::ios::binary);
       
        is.seekg((BodySectionOffset + RelativeOffset2) * 0x10, std::ios::beg);
        os.write(reinterpret_cast<char*>(&fill1), sizeof(fill1));
        os.write(reinterpret_cast<char*>(&width), sizeof(width));
        os.write(reinterpret_cast<char*>(&fill3), sizeof(fill3));
        os.write(reinterpret_cast<char*>(&height), sizeof(height));
        os.write(reinterpret_cast<char*>(&fill3), sizeof(fill3));
        os.write(reinterpret_cast<char*>(&fill1a), sizeof(fill1a));
        os.write(reinterpret_cast<char*>(&depth), sizeof(depth));
        os.write(reinterpret_cast<char*>(&fill2), sizeof(fill2));
        for (int j = 0; j < Filesize2; j++)
        {
            is.read(reinterpret_cast<char*>(&buf), sizeof(buf));
            os.write(reinterpret_cast<char*>(&buf), sizeof(buf));
        }
        os.close();
        is.close();
}

void Repack()
{
    std::ifstream is;
    std::ofstream os;
    is.open("common_textures_0_pc.rpack", std::ios::binary);
    DWORD magicID;
    is.read(reinterpret_cast<char*>(&magicID), sizeof(magicID));
    DWORD space1;
    is.read(reinterpret_cast<char*>(&space1), sizeof(space1));
    DWORD space2;
    is.read(reinterpret_cast<char*>(&space2), sizeof(space2));
    int Parts;
    is.read(reinterpret_cast<char*>(&Parts), sizeof(Parts));
    int Sections;
    is.read(reinterpret_cast<char*>(&Sections), sizeof(Sections));
    int Files;
    is.read(reinterpret_cast<char*>(&Files), sizeof(Files));
    int Fnames_Size;
    is.read(reinterpret_cast<char*>(&Fnames_Size), sizeof(Fnames_Size));
    int Fnames;
    is.read(reinterpret_cast<char*>(&Fnames), sizeof(Fnames));
    DWORD space3;
    is.read(reinterpret_cast<char*>(&space3), sizeof(space3));
    DWORD HeaderSectionStart;
    is.read(reinterpret_cast<char*>(&HeaderSectionStart), sizeof(HeaderSectionStart));
    int HeaderSectionOffset;
    is.read(reinterpret_cast<char*>(&HeaderSectionOffset), sizeof(HeaderSectionOffset));
    int HeaderSectionUnpackedSize;
    is.read(reinterpret_cast<char*>(&HeaderSectionUnpackedSize), sizeof(HeaderSectionUnpackedSize));
    int HeaderSectionPackedSize;
    is.read(reinterpret_cast<char*>(&HeaderSectionPackedSize), sizeof(HeaderSectionPackedSize));
    DWORD HeaderSectionSpace1;
    is.read(reinterpret_cast<char*>(&HeaderSectionSpace1), sizeof(HeaderSectionSpace1));
    DWORD BodySectionStart;
    is.read(reinterpret_cast<char*>(&BodySectionStart), sizeof(BodySectionStart));
    int BodySectionOffset;
    is.read(reinterpret_cast<char*>(&BodySectionOffset), sizeof(BodySectionOffset));
    int BodySectionUnpackedSize;
    is.read(reinterpret_cast<char*>(&BodySectionUnpackedSize), sizeof(BodySectionUnpackedSize));
    int BodySectionPackedSize;
    is.read(reinterpret_cast<char*>(&BodySectionPackedSize), sizeof(BodySectionPackedSize));
    DWORD BodySectionSpace1;
    is.read(reinterpret_cast<char*>(&BodySectionSpace1), sizeof(BodySectionSpace1));
    SHORT Filetype;
    SHORT Partindex;
    int RelativeOffset;
    int Filesize;
    int Unk;
    SHORT Filetype2;
    SHORT Partindex2;
    int RelativeOffset2;
    int Filesize2;
    int Unk2;
    int Tell1 = 0;
    int Tell2 = 0;
    int Tell3 = 0;
    int Tell4 = 0;
    int Tell5 = 0;
    int offsetfnames;
    int fnamesstart = 36 + 20 * Sections + 16 * Parts + Files * 12;
    BYTE fnamesbyte;
    SHORT width;
    SHORT height;
    SHORT depth;
    BYTE buf;
    BYTE fill1[0xc] = { 0x44, 0x44, 0x53, 0x20, 0x7C, 0x00, 0x00, 0x00, 0x07, 0x10, 0x0A, 0x00 };
    BYTE fill1a[0x4] = { 00, 00, 0x08, 00, };
    BYTE fill2[0x66] = { 0,0,0x01, 00, 00, 00, 00, 00, 00, 00, 00, 00,
        00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00,
        00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 0x20, 00, 00, 00, 0x04, 00, 00, 0x00, 0x44,
        0x58, 0x54, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 ,0x00 ,0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    BYTE fill3[2] = { 0,0 };

    for (int i = 0; i < Files; i++)
    {
        if (i > 0)
        {
            is.seekg(Tell3, std::ios::beg);
        }
        else
        {
            is.seekg(fnamesstart, std::ios::beg);
        }
        is.read(reinterpret_cast<char*>(&offsetfnames), sizeof(offsetfnames));
        Tell3 = is.tellg();
        is.seekg(0x1996FC, std::ios::beg);
        is.seekg(offsetfnames, SEEK_CUR);
        while (1)
        {
            is.read(reinterpret_cast<char*>(&fnamesbyte), sizeof(fnamesbyte));
            if (fnamesbyte == 0)
            {
                break;
            }

            std::cout << fnamesbyte;
        }
        std::cout << "           " + std::to_string(i);
        std::cout << std::endl;
    }
    is.seekg(0x4C, std::ios::beg);
    std::cout << "Input number to repack." << std::endl;
    int numinp1;
    std::cin >> numinp1;
    for (int i = 0; i < numinp1; i++)
    {


        is.read(reinterpret_cast<char*>(&Filetype), sizeof(Filetype));
        is.read(reinterpret_cast<char*>(&Partindex), sizeof(Partindex));
        is.read(reinterpret_cast<char*>(&RelativeOffset), sizeof(RelativeOffset));
        is.read(reinterpret_cast<char*>(&Filesize), sizeof(Filesize));
        is.read(reinterpret_cast<char*>(&Unk), sizeof(Unk));
        is.read(reinterpret_cast<char*>(&Filetype2), sizeof(Filetype2));
        is.read(reinterpret_cast<char*>(&Partindex2), sizeof(Partindex2));
        is.read(reinterpret_cast<char*>(&RelativeOffset2), sizeof(RelativeOffset2));
        is.read(reinterpret_cast<char*>(&Filesize2), sizeof(Filesize2));
        is.read(reinterpret_cast<char*>(&Unk2), sizeof(Unk2));
        Tell1 = is.tellg();
        if (i > 0)
        {
            is.seekg(Tell2, std::ios::beg);
        }
        else
        {
            is.seekg(HeaderSectionOffset * 0x10, std::ios::beg);
        }
        is.seekg(0x40, SEEK_CUR);
        is.read(reinterpret_cast<char*>(&width), sizeof(width));
        is.read(reinterpret_cast<char*>(&height), sizeof(height));
        is.read(reinterpret_cast<char*>(&depth), sizeof(depth));
        is.seekg(0xA, SEEK_CUR);
        Tell2 = is.tellg();
        is.seekg(BodySectionOffset + RelativeOffset, std::ios::beg);
        is.seekg(Filesize, SEEK_CUR);
        is.seekg(Tell1, std::ios::beg);
    }
    is.seekg(0, std::ios::beg);
    os.open("common_textures_0_pc_custom.rpack", std::ios::binary);
    for (int i = 0; i < ((BodySectionOffset + RelativeOffset) * 0x10); i++)
    {
        is.read(reinterpret_cast<char*>(&buf), sizeof(buf));
        os.write(reinterpret_cast<char*>(&buf), sizeof(buf));
    }
    Tell4 = is.tellg();
   // is.seekg((BodySectionOffset + RelativeOffset2) * 0x10, std::ios::beg);
    is.close();
    is.open("extraction.dds", std::ios::binary);
    is.seekg(0x80, std::ios::beg);
    for (int j = 0; j < Filesize2; j++)
    {
        is.read(reinterpret_cast<char*>(&buf), sizeof(buf));
        os.write(reinterpret_cast<char*>(&buf), sizeof(buf));
    }
    is.close();
    is.open("common_textures_0_pc.rpack", std::ios::binary);
    is.seekg(Tell4 + Filesize2, std::ios::beg);
    while (1)
    {
        is.read(reinterpret_cast<char*>(&buf), sizeof(buf));
        os.write(reinterpret_cast<char*>(&buf), sizeof(buf));
        if (is.peek() == EOF)
        {
            break;
        }
    }
    os.close();
    is.close();
}

void Inject()
{
     std::ifstream is;
    std::ofstream os;
    is.open("common_textures_0_pc.rpack", std::ios::binary);
    DWORD magicID;
    is.read(reinterpret_cast<char*>(&magicID), sizeof(magicID));
    DWORD space1;
    is.read(reinterpret_cast<char*>(&space1), sizeof(space1));
    DWORD space2;
    is.read(reinterpret_cast<char*>(&space2), sizeof(space2));
    int Parts;
    is.read(reinterpret_cast<char*>(&Parts), sizeof(Parts));
    int Sections;
    is.read(reinterpret_cast<char*>(&Sections), sizeof(Sections));
    int Files;
    is.read(reinterpret_cast<char*>(&Files), sizeof(Files));
    int Fnames_Size;
    is.read(reinterpret_cast<char*>(&Fnames_Size), sizeof(Fnames_Size));
    int Fnames;
    is.read(reinterpret_cast<char*>(&Fnames), sizeof(Fnames));
    DWORD space3;
    is.read(reinterpret_cast<char*>(&space3), sizeof(space3));
    DWORD HeaderSectionStart;
    is.read(reinterpret_cast<char*>(&HeaderSectionStart), sizeof(HeaderSectionStart));
    int HeaderSectionOffset;
    is.read(reinterpret_cast<char*>(&HeaderSectionOffset), sizeof(HeaderSectionOffset));
    int HeaderSectionUnpackedSize;
    is.read(reinterpret_cast<char*>(&HeaderSectionUnpackedSize), sizeof(HeaderSectionUnpackedSize));
    int HeaderSectionPackedSize;
    is.read(reinterpret_cast<char*>(&HeaderSectionPackedSize), sizeof(HeaderSectionPackedSize));
    DWORD HeaderSectionSpace1;
    is.read(reinterpret_cast<char*>(&HeaderSectionSpace1), sizeof(HeaderSectionSpace1));
    DWORD BodySectionStart;
    is.read(reinterpret_cast<char*>(&BodySectionStart), sizeof(BodySectionStart));
    int BodySectionOffset;
    is.read(reinterpret_cast<char*>(&BodySectionOffset), sizeof(BodySectionOffset));
    int BodySectionUnpackedSize;
    is.read(reinterpret_cast<char*>(&BodySectionUnpackedSize), sizeof(BodySectionUnpackedSize));
    int BodySectionPackedSize;
    is.read(reinterpret_cast<char*>(&BodySectionPackedSize), sizeof(BodySectionPackedSize));
    DWORD BodySectionSpace1;
    is.read(reinterpret_cast<char*>(&BodySectionSpace1), sizeof(BodySectionSpace1));
    SHORT Filetype;
    SHORT Partindex;
    int RelativeOffset;
    int Filesize;
    int Unk;
    SHORT Filetype2;
    SHORT Partindex2;
    int RelativeOffset2;
    int Filesize2;
    int Unk2;
    int Tell1 = 0;
    int Tell2 = 0;
    int Tell3 = 0;
    int offsetfnames;
    int fnamesstart = 36 + 20 * Sections + 16 * Parts + Files * 12;
    BYTE fnamesbyte;
    SHORT width;
    SHORT height;
    SHORT depth;
    BYTE buf;
    BYTE fill1[0xc] = { 0x44, 0x44, 0x53, 0x20, 0x7C, 0x00, 0x00, 0x00, 0x07, 0x10, 0x0A, 0x00 };
    BYTE fill1a[0x4] = { 00, 00, 0x08, 00, };
    BYTE fill2[0x66] = { 0,0,0x01, 00, 00, 00, 00, 00, 00, 00, 00, 00,
        00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00,
        00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 0x20, 00, 00, 00, 0x04, 00, 00, 0x00, 0x44,
        0x58, 0x54, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 ,0x00 ,0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    BYTE fill3[2] = { 0,0 };

    for (int i = 0; i < Files; i++)
    {
        if (i > 0)
        {
            is.seekg(Tell3, std::ios::beg);
        }
        else
        {
            is.seekg(fnamesstart, std::ios::beg);
        }
        is.read(reinterpret_cast<char*>(&offsetfnames), sizeof(offsetfnames));
        Tell3 = is.tellg();
        is.seekg(0x1996FC, std::ios::beg);
        is.seekg(offsetfnames, SEEK_CUR);
        while (1)
        {
            is.read(reinterpret_cast<char*>(&fnamesbyte), sizeof(fnamesbyte));
            if (fnamesbyte == 0)
            {
                break;
            }
            
            std::cout << fnamesbyte;
        }
        std::cout << "           " + std::to_string(i);
        std::cout << std::endl;
    }
    is.seekg(0x4C, std::ios::beg);
    std::cout << "Input number to inject." << std::endl;
    int numinp1;
    std::cin >> numinp1;
    for (int i = 0; i < numinp1; i++)
    {
       
        
        is.read(reinterpret_cast<char*>(&Filetype), sizeof(Filetype));
        is.read(reinterpret_cast<char*>(&Partindex), sizeof(Partindex));
        is.read(reinterpret_cast<char*>(&RelativeOffset), sizeof(RelativeOffset));
        is.read(reinterpret_cast<char*>(&Filesize), sizeof(Filesize));
        is.read(reinterpret_cast<char*>(&Unk), sizeof(Unk));
        is.read(reinterpret_cast<char*>(&Filetype2), sizeof(Filetype2));
        is.read(reinterpret_cast<char*>(&Partindex2), sizeof(Partindex2));
        is.read(reinterpret_cast<char*>(&RelativeOffset2), sizeof(RelativeOffset2));
        is.read(reinterpret_cast<char*>(&Filesize2), sizeof(Filesize2));
        is.read(reinterpret_cast<char*>(&Unk2), sizeof(Unk2));
        Tell1 = is.tellg();
        if (i > 0)
        {
            is.seekg(Tell2, std::ios::beg);
        }
        else
        {
            is.seekg(HeaderSectionOffset * 0x10, std::ios::beg);
        }
        is.seekg(0x40, SEEK_CUR);
        is.read(reinterpret_cast<char*>(&width), sizeof(width));
        is.read(reinterpret_cast<char*>(&height), sizeof(height));
        is.read(reinterpret_cast<char*>(&depth), sizeof(depth));
        is.seekg(0xA, SEEK_CUR);
        Tell2 = is.tellg();
        is.seekg(BodySectionOffset + RelativeOffset, std::ios::beg);
        is.seekg(Filesize, SEEK_CUR);
        is.seekg(Tell1, std::ios::beg);
    }


       
    is.close();
    os.close();
    is.open("extraction.dds", std::ios::binary);
    is.seekg(0x80, std::ios::beg);
    os.open("common_textures_0_pc.rpack", std::ios::in || std::ios::out || std::ios::binary);
    os.seekp(((BodySectionOffset + RelativeOffset2) * 0x10), std::ios::beg);
        
        for (int j = 0; j < Filesize2; j++)
        {
            
            
            is.read(reinterpret_cast<char*>(&buf), sizeof(buf));
            os.write(reinterpret_cast<char*>(&buf), sizeof(buf));
        }
        os.close();
        is.close();
}

int main()
{
    
    std::cout << "What would you like to do?" << std::endl << "Unpack" << std::endl << "Repack" << std::endl << "Inject" << std::endl;
    std::string cin1;
    std::cin >> cin1;
    if (cin1 == "Unpack")
    {
        Unpack();
    }
    else if (cin1 == "Repack")
    {
        Repack();
    }
    else if (cin1 == "Inject")
    {
        Inject();
    }
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
