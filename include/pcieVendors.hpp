/*
// Copyright (c) 2019 intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#pragma once
#include <boost/container/flat_map.hpp>

static constexpr char const* otherVendor = "Other";

// This list of Vendors is extracted from the PCI-SIG member-companies page
// ('https://pcisig.com/membership/member-companies') using
// GetPCI-SIGVendorIDMap.py
static boost::container::flat_map<int, std::string> pciVendors{
    {0x1E4A, "2CRSI SA"},
    {0x12B9, "3Com Corp, Modem Division"},
    {0xA727, "3Com Corporation"},
    {0x10B7, "3Com Corporation"},
    {0x1DA0, "3M Company"},
    {0x13C1, "3ware Inc"},
    {0x38EF, "4Links Limited"},
    {0x1872, "A & D Company, Ltd"},
    {0x160D, "AAEON Electronics, Inc."},
    {0x1D28, "Aava Mobile Oy"},
    {0x1D92, "Abaco Systems Inc."},
    {0x13DE, "ABB AB"},
    {0x1C85, "ABLIC Inc."},
    {0xAC1A, "Acacia Communications Inc"},
    {0x14D6, "Accusys Storage LTD."},
    {0x18E4, "Acer Inc."},
    {0x1C94, "Aces Electronics Co., Ltd."},
    {0x1B59, "Achronix Semiconductor"},
    {0x1528, "ACKSYS"},
    {0x1DE8, "Acqiris SA"},
    {0x1C2A, "Acromag inc"},
    {0x1DE2, "Action Star Technology Co., Ltd."},
    {0x4153, "Active Silicon, Ltd."},
    {0x9004, "Adaptec"},
    {0x9005, "Adaptec"},
    {0x1CC1, "ADATA Technology Co., Ltd."},
    {0x15B8, "ADDI-DATA Gmbh"},
    {0x144A, "Adlink Technology, Inc."},
    {0x1CDA, "ADTEC Corporation"},
    {0x1022, "Advanced Micro Devices"},
    {0x1002, "Advanced Micro Devices, Inc. [AMD/ATI]"},
    {0x10CD, "Advanced System Products, Inc"},
    {0x130F, "Advanet, Inc."},
    {0x13FE, "Advantech Co., Ltd."},
    {0x1850, "Advantest Corporation"},
    {0x1D7C, "Aerotech Inc"},
    {0x1CF6, "Aetina Corporation"},
    {0x1DC4, "Agylstor, Inc."},
    {0x193F, "AHA Products Group of Comtech EF Data Corp."},
    {0x1B76, "AIC Inc."},
    {0x1447, "AIM GmbH"},
    {0x4149, "AIMOTIVE Kft."},
    {0x1D36, "Airbus Defence and Space GmbH"},
    {0x1ACD, "Airbus DS Electronics and Border Security GmbH"},
    {0xF1D0, "AJA Video"},
    {0x1CF0, "Akitio"},
    {0x1096, "Alacron"},
    {0x1C0B, "Alazar Technologies, Inc."},
    {0x1DC2, "Alco Digital Devices Limited"},
    {0x1DED, "Alibaba (China) Co., Ltd."},
    {0x1B49, "ALLDIS Computersystem GmbH"},
    {0x1259, "Allied Telesis Inc."},
    {0x1D04, "Allied Vision Technologies"},
    {0x194F, "Allion Labs, Inc."},
    {0x1D67, "Alltop Technology Co., Ltd"},
    {0x4144, "Alpha Data Parallel Systems, Ltd."},
    {0xAD00, "Alta Data Technologies"},
    {0x1D0F, "Amazon"},
    {0x101E, "American Megatrends Inc."},
    {0x1DEF, "Ampere Computing, LLC"},
    {0x18F8, "Amphenol Corp."},
    {0x1BFB, "Analog Bits, Inc"},
    {0x11D4, "Analog Devices Inc."},
    {0x12D6, "Analogic Corp"},
    {0x1B12, "Analogix Semiconductor"},
    {0x12DB, "Annapolis Micro Systems, Inc."},
    {0x1C36, "Annapurna Labs"},
    {0x1852, "Anritsu Corporation"},
    {0x19EC, "ANSYS, Inc."},
    {0x1BCD, "Apacer Technology Inc."},
    {0x106B, "Apple Computer"},
    {0x1D6A, "Aquantia Corp"},
    {0x17D3, "Areca Technology Corp."},
    {0x13E6, "ARGOSY RESEARCH INC."},
    {0x1E28, "Aricent INC"},
    {0x1AA1, "Aristocrat Technologies Australia Pty Ltd."},
    {0x13B5, "ARM Ltd."},
    {0x1E17, "Arnold & Richter Cine Technik GmbH & Co. Betriebs KG"},
    {0x1E42, "ART Beijing Science and Technology Development Co., Ltd."},
    {0x1DB4, "Arteris Inc."},
    {0x1223, "Artesyn Embedded Technologies"},
    {0x1792, "Artiza Networks, Inc."},
    {0x1AC0, "Aselsan Inc."},
    {0x144F, "Askey Computer Corporation"},
    {0x1E4D, "Asolid Technology Co., Ltd."},
    {0x1A03, "ASPEED Technology Inc."},
    {0x1C18, "Asset InterTech Inc"},
    {0x19D7, "Astek Corporation"},
    {0x11BF, "Astrodesign,  Inc."},
    {0x1BD0, "Astronics Corporation"},
    {0x1043, "Asustek Computer, Inc."},
    {0x1D58, "Atech Flash Technology, Inc"},
    {0x1735, "Aten International Co., Ltd."},
    {0x1DB2, "ATP Electronics, Inc."},
    {0x1BDD, "Atrust Computer Corp."},
    {0x1D8B, "Attala Systems"},
    {0x175C, "AudioScience Inc."},
    {0x1D50, "Aurotek Corporation"},
    {0x1A1F, "Avago Technologies"},
    {0x1DD7, "AVAL DATA Corporation"},
    {0x1264, "Aval Nagasaki Corporation"},
    {0x1461, "AVerMedia Technologies, Inc."},
    {0x18EF, "Avery Design systems, Inc."},
    {0x1A15, "Axell Corporation"},
    {0x1E0C, "Axiomtek Co., Ltd."},
    {0x1A3B, "AzureWave Technologies Inc."},
    {0x1D84, "b-plus GmbH"},
    {0x1B9F, "BAE Systems"},
    {0x1D22, "Baidu"},
    {0x13CC, "Barco, Inc."},
    {0x1D1C, "Barefoot Networks, Inc."},
    {0x1217, "BayHub Technology Inc"},
    {0x17CE, "BCM Advanced Research"},
    {0x1C78, "Bechtel Marine Propulsion Corporation"},
    {0x1C2F, "Beckhoff Automation GmbH & Co. KG"},
    {0x1E18, "Beijing GuangRunTong Technology Development Co.,Ltd"},
    {0x9588, "Beijing JCZ Technology Co., Ltd"},
    {0x1C5F, "Beijing Memblaze Technology Co. Ltd."},
    {0x1D6F, "Beijing Pinecone Electronics Co., Ltd"},
    {0x1DCF, "Beijing Sinead Technology Co., Ltd."},
    {0x9D32, "Beijing Starblaze Technology Co., LTD."},
    {0x8088, "Beijing Wangxun Technology Co., Ltd."},
    {0x1799, "Belkin Corporation"},
    {0x1C75, "Bellwether Electronic Corp."},
    {0x1B05, "Benchmark Electronics, Inc."},
    {0x3442, "Bihl + Wiedemann GmbH"},
    {0x1C6F, "Bios Corporation"},
    {0x1A11, "BitifEye Digital Test Solutions GmbH"},
    {0x1E30, "Bitmain Technologies Inc."},
    {0x192A, "BiTMICRO Networks, Inc."},
    {0x12BA, "Bittware, Inc."},
    {0x7248, "BizLink Technology, Inc."},
    {0x1C05, "Blackberry QNX"},
    {0x1D74, "BlackLynx, Inc."},
    {0xBDBD, "Blackmagic Design Pty Ltd"},
    {0x15E0, "Blue Coat Systems"},
    {0x16F2, "Bosch Rexroth AG"},
    {0x1E16, "BOXX Technologies, LLC"},
    {0x1166, "Broadcom"},
    {0x182F, "Broadcom"},
    {0x1000, "Broadcom / LSI"},
    {0x166D, "Broadcom Corporation"},
    {0xFEDA, "Broadcom Inc"},
    {0x14E4, "Broadcom Limited"},
    {0x1154, "Buffalo Inc."},
    {0x1E3D, "Burlywood, Inc"},
    {0x104B, "BusLogic"},
    {0x1BCB, "Bustec Production Ltd."},
    {0x1E3A, "Cactus Technologies, Limited"},
    {0x17CD, "Cadence Design Systems"},
    {0xCABC, "Cambricon Technologies Corporation Limited"},
    {0xCA3B, "Cambrionix Ltd."},
    {0x11AC, "Canon, Inc."},
    {0x197D, "Cap Co., Ltd."},
    {0x1C96, "Carina System Co., Ltd."},
    {0x1DD9, "Casa Systems, Inc."},
    {0x1ACD, "Cassidian"},
    {0x1657, "Cavium QLogic"},
    {0x177D, "Cavium, Inc."},
    {0x1D69, "Celeno Communications (Israel) LTD"},
    {0x18D4, "Celestica"},
    {0x123C, "Century Systems, Inc."},
    {0x10DC, "CERN"},
    {0x0731, "Changsha Jingjia Microelectronics Co., Ltd."},
    {0x1CEE, "Chant Sincere Co., Ltd."},
    {0x1E08, "Charon Technologies"},
    {0x1425, "Chelsio Communications"},
    {0x1D94, "Chengdu Higon Integrated Circuit Design Co., Ltd."},
    {0x1E4E, "Chongqing Unisinsight Technology Co.,Ltd."},
    {0x1A43, "Chuo Electronics Co., Ltd."},
    {0x1D47, "Ciena Corporation"},
    {0x1013, "Cirrus Logic, Inc."},
    {0x1137, "Cisco Systems, Inc."},
    {0x5853, "Citrix Systems UK Ltd"},
    {0x1558, "Clevo Co."},
    {0x1D1D, "CNEX LABS Inc."},
    {0x12B7, "Cognex Corporation"},
    {0x1830, "Cohu, Inc."},
    {0x1D38, "Colorado Engineering Inc."},
    {0x18F7, "Commtech, Inc."},
    {0x1DE6, "Communication Automation Corporation"},
    {0x14C0, "Compal Electronics, Inc."},
    {0x1C69, "Comtel Electronics GmbH"},
    {0x0E11, "Compaq Computer Corporation"},
    {0x125F, "Concurrent Technologies"},
    {0x1C9B, "Conduant Corporation"},
    {0x1A2F, "Congatec AG"},
    {0x12C4, "Connect Tech Inc"},
    {0x1221, "Contec Co., Ltd"},
    {0x1571, "Contemporary Controls  Systems Inc."},
    {0x1C6B, "Corsair Memory"},
    {0x1C46, "Cosmotechs Co., Ltd."},
    {0x1D80, "COTS Technology"},
    {0x136C, "CPI Technologies, Inc."},
    {0x17DB, "Cray, Inc."},
    {0x1102, "Creative Technology"},
    {0x1E23, "Credo Semiconductor, Inc."},
    {0x1DFD, "CRU-INC"},
    {0xCCEC, "Curtiss-Wright Controls Embedded Computing"},
    {0x19EB, "DAIHEN Corporation"},
    {0x1BFA, "Daiichi Jitsugyo Viswill Co., Ltd"},
    {0x1C33, "Daktronics"},
    {0x1E35, "Danaks, UAB"},
    {0x194A, "Dap Holding B.V."},
    {0x0303, "DAQ System"},
    {0x1D91, "DAQRI LABS"},
    {0x1E1A, "DataDirect Networks"},
    {0x1CB8, "Dawning Information Industry Co., Ltd."},
    {0x1DC3, "Deep Insights Inc."},
    {0x1A0E, "DekTec Digital Video B.V."},
    {0x1E33, "Delkin Devices"},
    {0x1028, "Dell Computer Corporation"},
    {0x1120, "Dell EMC"},
    {0x1A05, "Delta Electronics, Inc."},
    {0x1B66, "Deltatec"},
    {0x1192, "Densan Co., Ltd."},
    {0x1C04, "Dexon Systems Ltd"},
    {0x15BD, "DFI Inc."},
    {0x1D4C, "Diamanti, Inc."},
    {0x1369, "Digigram"},
    {0xDD01, "Digital Devices"},
    {0x1011, "Digital Equipment Corporation"},
    {0x18FD, "Digital Media Professionals, Inc."},
    {0xD161, "Digium, Inc."},
    {0x17DF, "Dini Group LaJolla Inc."},
    {0x1B31, "DisplayLink (UK) Ltd"},
    {0x119D, "DMG MORI B.U.G. CO., LTD."},
    {0x1D0C, "Dolby Laboratories, Inc."},
    {0x11C8, "Dolphin Interconnect Solutions AS"},
    {0x4453, "dSPACE GmbH"},
    {0x134A, "DTC Technology Corp."},
    {0x1D3E, "DTS INSIGHT CORPORATION"},
    {0x1BFC, "duagon AG"},
    {0x3100, "Dynabook Inc."},
    {0x1197, "DynamicSignals, LLC"},
    {0x1B98, "E.E.P.D. GmbH"},
    {0x177C, "EBRAINS, INC."},
    {0x1DD6, "ECRIN SYSTEMS"},
    {0x1428, "EDEC Linsey System"},
    {0x1E2D, "Edge Networks LLC"},
    {0x1DE5, "Eideticom"},
    {0x181D, "eInfochips, Inc."},
    {0x1227, "EIZO Rugged Solutions"},
    {0xE4BF, "EKF Elektronik GmbH"},
    {0x1E13, "Elbit Systems"},
    {0xE1C5, "Elcus Electronic Company JSC"},
    {0x13B9, "ELECOM CO LTD"},
    {0x1C7F, "Elektrobit Austria GmbH"},
    {0x1D4B, "Elektrosfera LTD."},
    {0x1019, "Elitegroup Computer Systems Inc."},
    {0x1E25, "Elk Solutions, LLC"},
    {0x1C24, "Elma Electronic Inc"},
    {0x1433, "Eltec Elektronik AG"},
    {0x2782, "Emdoor Digital Technology Co., Ltd."},
    {0xEACE, "Endace Technology Ltd."},
    {0x123D, "Engineering Design Team, Inc."},
    {0x1D8F, "ENYX"},
    {0x1D89, "EpoStar Electronics Corp."},
    {0x1A25, "Ericsson AS"},
    {0x1E20, "ERNI Deutschland GmbH"},
    {0x12FE, "esd electronics gmbh"},
    {0x1E10, "eSOL Co.,Ltd."},
    {0x1E0A, "Esperanto Technologies, Inc"},
    {0x1E45, "ESSENCORE Limited"},
    {0x1DF3, "Ethernity Networks Ltd"},
    {0x1977, "Etion Create (Pty) Ltd."},
    {0x1058, "ETRI"},
    {0x1B6F, "Etron Technology, Inc."},
    {0x1805, "Euresys SA"},
    {0x1E19, "Eurofins Digital Testing Belgium NV"},
    {0x1766, "Eurotech Spa"},
    {0x1D86, "Evertz Microsystems Ltd."},
    {0x3842, "EVGA Corporation"},
    {0x1BC1, "EXFO Inc."},
    {0x1E05, "Exicon Co., Ltd."},
    {0x1CAD, "EXTOLL GmbH"},
    {0x5845, "Extreme Engineering Solutions"},
    {0xF5F5, "F5 Networks, Inc."},
    {0x1D9B, "Facebook"},
    {0x1DC5, "FADU Inc."},
    {0x188B, "Faraday Technology Corporation"},
    {0x1463, "Fast Corporation"},
    {0x1D8C, "FASTWEL Group Co. Ltd"},
    {0x1D8D, "Fiberhome Telecommunication Technologies"},
    {0x1CF8, "Fibocom Wireless Inc."},
    {0x1E1B, "Firm INFORMTEST Ltd."},
    {0x22B8, "Flex Logix Technologies, Inc."},
    {0x1895, "Flextronics International"},
    {0x1CB5, "Focusrite Audio Engineering Ltd"},
    {0x1778, "For-A Company Limited"},
    {0x1165, "Foresight Imaging LLC"},
    {0x1E1D, "Form, LLC"},
    {0x1A29, "Fortinet, Inc."},
    {0x1DC6, "Fox Crypto B.V."},
    {0x105B, "Foxconn Interconnect Technology, Ltd."},
    {0x1B73, "Fresco Logic, Inc."},
    {0x16EA, "Fuji Electric Systems Co., Ltd."},
    {0x1135, "Fuji Xerox Co Ltd"},
    {0x127F, "FUJIFILM Corporation"},
    {0x1183, "Fujikura Ltd."},
    {0x10CF, "Fujitsu Limited"},
    {0x1E1F, "Full Wise Technology Limited"},
    {0x1DAD, "Fungible, Inc."},
    {0x1D87, "Fuzhou Rockchip Electronics Co., Ltd"},
    {0x1796, "FZ Juelich"},
    {0x1B4C, "Galaxy Microsystems Ltd."},
    {0x17F9, "GemTek Technology Co., Ltd."},
    {0x123, "General Dynamics"},
    {0x1775, "General Electric"},
    {0x1C6E, "General Standards Corp"},
    {0x1D32, "Genesis Co.,Ltd"},
    {0x1DCB, "Genesis Technology USA, Inc."},
    {0x17A0, "Genesys Logic, Inc."},
    {0x15E7, "GET Engineering Corp."},
    {0x165C, "Gidel Ltd."},
    {0x1458, "Giga-Byte Technology Co., Ltd."},
    {0x1AC1, "Global Unichip Corp."},
    {0x1D70, "GLOBALFOUNDRIES U.S. 2 LLC"},
    {0x1D56, "Glyph Production Technologies"},
    {0x140E, "GOEPEL electronic GmbH"},
    {0x1D2D, "Good Way Technology Co., Ltd."},
    {0x1AE0, "Google, Inc."},
    {0x1A83, "Gopher Inc."},
    {0x1C5E, "GopherTec Inc."},
    {0x1BD7, "Granite River Labs Inc."},
    {0x1D95, "Graphcore Ltd"},
    {0x1FCA, "Grass Valley"},
    {0x1B95, "Green Hills Software"},
    {0x1BF5, "Greenliant Systems"},
    {0x1DE0, "Groq, Inc."},
    {0x1E4C, "GSI Technology"},
    {0x1DBF, "Guizhou Huaxintong Semiconductor Technology Co.,Ltd"},
    {0x6D5E, "Guntermann & Drunck GmbH"},
    {0x1253, "Guzik Technical Enterprises"},
    {0x1E00, "Gyrfalcon Technology Inc"},
    {0x1DA3, "Habana Labs"},
    {0x1D29, "Hagiwara Solutions Co., Ltd."},
    {0x11A1, "Hamamatsu Photonics K.K."},
    {0x3086, "Hangzhou Hikvision Digital Technology Co., Ltd."},
    {0x1C42, "Harman Automotive Division"},
    {0x1738, "Harris Corporation (GCSD)"},
    {0x19CB, "Hartmann Electronic GmbH"},
    {0x19A6, "HDL Design House"},
    {0x112B, "Heidelberger Druckmaschinen AG"},
    {0x1ACD, "Hensoldt Sensors GmbH"},
    {0x103C, "Hewlett Packard"},
    {0x1590, "Hewlett Packard Enterprise"},
    {0x1DEA, "Hibertek International Limited"},
    {0x13A3, "Hifn Inc."},
    {0x1103, "HighPoint Technologies, Inc."},
    {0x15CF, "Hilscher GmbH"},
    {0x184C, "Hirose Electric USA Inc."},
    {0x1FCD, "Hitachi High-Technologies Corporation"},
    {0x1250, "Hitachi Ulsi Systems Co Ltd"},
    {0x1367, "Hitachi Zosen Corporation"},
    {0x1054, "Hitachi, Ltd"},
    {0x14A9, "Hivertec Inc."},
    {0x10AC, "Honeywell Inc."},
    {0x1426, "HRCP Research and Development Partnership"},
    {0x19E5, "Huawei Technologies Co., Ltd."},
    {0x21B4, "Hunan Goke Microelectronics Co., Ltd."},
    {0x1DD2, "I-CUBE TECHNOLOGY co., ltd"},
    {0x10FC, "I-O Data Device, Inc."},
    {0x18F2, "I-PEX (Dai-ichi Seiko)"},
    {0x1AAC, "IBASE Technology Inc."},
    {0x11CA, "IBEX Technology, Co. Ltd."},
    {0x1014, "IBM"},
    {0x1B53, "iD corporation"},
    {0x111D, "IDT (PMC/Microsemi/Microchip)"},
    {0x180C, "IEI Integration Corp."},
    {0x1C9D, "Illumina"},
    {0x1E3E, "Iluvatar CoreX Inc. Nanjing"},
    {0x1D65, "Imagine Communications Corp."},
    {0x1898, "Imaging Business Machines LLC"},
    {0x15D1, "Infineon Technologies AG"},
    {0x1D5B, "Infinera Corp."},
    {0x1C1D, "Infocus Corp"},
    {0x1BC0, "InnoDisk Corporation"},
    {0x1DBE, "INNOGRIT CORPORATION"},
    {0x1CFB, "Innotech Corporation"},
    {0x1771, "InnoVision Multimedia, Ltd."},
    {0x1D98, "Innovium, Inc."},
    {0x1BD4, "Inspur Electronic Information Industry Co., Ltd."},
    {0x1D4D, "Integrated Design Tools, Inc."},
    {0x8086, "Intel Corporation"},
    {0x1739, "Interface Concept"},
    {0x1147, "Interface Corporation"},
    {0x1A6E, "International Game Technology"},
    {0x1BDC, "Intrado Inc."},
    {0x1E12, "Introspect Technology"},
    {0x1D2F, "INVECAS, Inc."},
    {0x1170, "Inventec Corporation"},
    {0x1546, "IOI Technology Corporation"},
    {0x1E50, "IP3 Tech (HK) Limited"},
    {0x1DB6, "Irvin Technologies, Inc."},
    {0x1BEE, "IXXAT Automation GmbH"},
    {0x1817, "JAE"},
    {0x1D12, "JESS-LINK PRODUCTS CO., LTD."},
    {0x1DBC, "JitterLabs LLC"},
    {0x197B, "JMicron Technology Corporation"},
    {0x1E2B, "Jorjin Technologies Inc."},
    {0x1304, "Juniper Networks"},
    {0x13D6, "K.I. Technology Co., Ltd"},
    {0x18B2, "K.K. Rocky"},
    {0x1D26, "KALRAY"},
    {0x13A1, "Kawasaki Heavy Industries Ltd."},
    {0x1D2A, "KAYA Instruments Ltd"},
    {0xCEBA, "KEBA AG"},
    {0x1A3F, "KEL Corporation"},
    {0x1B2A, "Keyence Corporation"},
    {0x15BC, "Keysight Technologies"},
    {0x1E04, "KeyW Corporation"},
    {0x2646, "Kingston Technology Company"},
    {0x1D7E, "KISTI"},
    {0x1BBA, "KLA-Tencor"},
    {0x1CA2, "KnowledgeTek, Inc."},
    {0x1D90, "KnuEdge Inc."},
    {0x1629, "Kongsberg Spacetec A.S."},
    {0x16CB, "Konica Minolta Inc."},
    {0x1059, "Kontron"},
    {0x1A07, "Kvaser AB"},
    {0x1893, "Kyocera Corporation"},
    {0x1341, "Kyoto Microcomputer Co., Ltd."},
    {0x1C2D, "L-3 Chesapeake Sciences Corporation"},
    {0x1204, "Lattice Semiconductor Corporation"},
    {0x1407, "Lava Computer Mfg Inc"},
    {0x107D, "Leadtek Research Inc."},
    {0x1CE1, "Lecoln Technology Co., Ltd."},
    {0x17AA, "Lenovo"},
    {0x126A, "Lexmark International,  Inc."},
    {0x1E29, "LIBERTRON Co., Ltd."},
    {0x1D9A, "LightBits Labs Ltd."},
    {0x1E3F, "Linaro Limited"},
    {0x1D14, "Lintes Technology Co., Ltd."},
    {0x1DCD, "Liqid Inc"},
    {0x14A4, "Lite-On Technology Corporation"},
    {0x1E03, "Logic Supply, Inc."},
    {0x1DBD, "Logic-Fruit Technologies Pvt. Ltd"},
    {0x0014, "Loongson Technology Corporation Limited"},
    {0x1880, "LOTES Co., Ltd"},
    {0x1DFC, "LTD NTCOM"},
    {0x1BDF, "LUXSHARE-ICT Co., Ltd."},
    {0x1CAB, "Lynx Software Technologies, Inc."},
    {0x1D27, "M31 Technology Corporation"},
    {0x1916, "Macnica Inc."},
    {0x137A, "Mark of the Unicorn Inc"},
    {0x1148, "Marvell Semiconductor, Inc."},
    {0x1B4B, "Marvell Technology Group Ltd."},
    {0x11AB, "Marvell Technology Group Ltd."},
    {0x16E2, "Marvin Test Solutions, Inc."},
    {0x102B, "Matrox Graphics, Inc."},
    {0x1BBF, "Maxeler Technologies Ltd."},
    {0x1E4B, "Maxio Technology (Hangzhou) Ltd."},
    {0x1DB8, "Maxiotek Corporation"},
    {0x1E43, "MaxLinear Inc"},
    {0x1DD0, "McDowell Signal Processing, LLC"},
    {0x1AA2, "Media Links Co., LTD."},
    {0x14C3, "MediaTek Incorporation"},
    {0x1E39, "MEDION AG"},
    {0x136B, "MegaChips Corporation"},
    {0x10A0, "Meidensha Corporation"},
    {0x1360, "Meinberg Funkuhren GmbH & Co. KG"},
    {0x152E, "Melec Inc"},
    {0x15B3, "Mellanox Technologies"},
    {0x1CA0, "MEMORIGHT"},
    {0x1A88, "MEN Mikro Elektronik GmbH"},
    {0x14AB, "Mentor Graphics Corporation"},
    {0x1E2E, "Mercedes-Benz R&D North America, Inc."},
    {0x1134, "Mercury Computer Systems"},
    {0x1E06, "Micro Brain, Inc."},
    {0x1A3E, "Micro-Research Finland Oy"},
    {0x1462, "Micro-Star International Co ., Ltd."},
    {0x0054, "Microchip Technology"},
    {0x1344, "Micron Technology Inc"},
    {0x1414, "Microsoft"},
    {0x4D54, "Microtechnica Co., Ltd."},
    {0x22DB, "Missing Link Electronics, Inc."},
    {0x1DAF, "MIT Lincoln Laboratory"},
    {0x1071, "MiTAC International Corporation"},
    {0x10BA, "Mitsubishi Electric Corporation"},
    {0x1547, "Mitutoyo Corporation"},
    {0x1C8C, "Mobiveil"},
    {0x10D2, "Molex Inc."},
    {0x1B00, "Montage Technology"},
    {0xC0FE, "Motion Engineering"},
    {0x1DFE, "Motorola Solutions"},
    {0x18E6, "MPL AG"},
    {0x1B08, "MSC Technologies GmbH"},
    {0x1322, "MTT Corporation"},
    {0x1B7B, "Multisuns Corporation"},
    {0x1069, "Mylex Corporation"},
    {0x1E53, "Mythic - AI"},
    {0x198A, "Nallatech"},
    {0x1CFC, "Naltec, Inc."},
    {0x1B8F, "Nanoteq (Pty) Ltd"},
    {0x18F4, "Napatech A/S"},
    {0x1093, "National Instruments"},
    {0x1BCF, "NEC"},
    {0x1D85, "Neosem Holdings Inc"},
    {0x1275, "NetApp, Inc."},
    {0x1B26, "Netcope Technologies a.s."},
    {0x1D82, "NETINT Technologies Inc."},
    {0x1C1B, "Netlist, Inc."},
    {0x19EE, "Netronome"},
    {0x193D, "New H3C Technologies Co., Ltd."},
    {0x1E61, "New Telecommunication Technologies LLC"},
    {0xAD10, "New Wave Design and Verification, LLC"},
    {0x149D, "NewTek"},
    {0x1933, "Nexcom International"},
    {0x1DBB, "NGD Systems, Inc."},
    {0x1C63, "NICEVT JSC"},
    {0x1BB2, "Nikon Corporation"},
    {0x12E1, "Nintendo Co., Ltd."},
    {0x13B8, "Nokia Solutions and Networks"},
    {0x1E11, "Northern Han Trade Co., Limited"},
    {0x1B0C, "Northrop Grumman Corp., Electronic Systems"},
    {0x19AA, "Northwest Logic, Inc."},
    {0x0222, "Not for Radio, LLC"},
    {0x1CBD, "Novachips Co., Ltd."},
    {0x1D37, "NovaSparks"},
    {0x1E09, "Novatek Microelectronics Corporation"},
    {0x1E02, "NSITEXE, Inc."},
    {0x12A4, "NTT Electronics Corp."},
    {0x1808, "nVent, Schroff GmbH"},
    {0x10DE, "NVidia Corporation"},
    {0x1DE9, "NVXL Technology Inc."},
    {0x1131, "NXP Semiconductors"},
    {0x0C10, "Oclaro Inc"},
    {0x16C8, "Octasic Inc."},
    {0x1795, "OKB SAPR"},
    {0x1021, "Oki Electric Industry Co. Ltd."},
    {0x1270, "Olympus Corporation"},
    {0x10CB, "Omron Corporation"},
    {0x160C, "OMS Motion, Inc."},
    {0x1529, "ON Semiconductor"},
    {0x1954, "One Stop Systems, Inc."},
    {0x1DF7, "opencpi.org"},
    {0x18FE, "Opex Corporation"},
    {0x17E3, "OPTEON Corporation"},
    {0x148A, "OPTO 22"},
    {0x108E, "Oracle"},
    {0x1DA4, "Orient Semiconductor Electronics, Ltd."},
    {0x1576, "Osprey Video"},
    {0x169A, "Otari, Inc."},
    {0x1C7A, "Other World Computing"},
    {0x19A4, "Owl Cyber Defense Solutions LLC"},
    {0x1569, "Palit Microsystems Ltd."},
    {0x1DA6, "Palodex Group Oy"},
    {0x1189, "Panasonic Corporation"},
    {0x1AF8, "Parade Technologies, Inc."},
    {0x1AB8, "Parallels International GmbH"},
    {0x1CE5, "PARPRO, Inc."},
    {0x1D99, "Pattern Computer Inc."},
    {0x174B, "PC Partner Limited"},
    {0x001C, "PEAK-System Technik GmbH"},
    {0x1B0A, "Pegatron Corporation"},
    {0x1DD8, "Pensando Systems"},
    {0x12D8, "Pericom Semiconductor"},
    {0x1FCB, "PerkinElmer"},
    {0x155F, "Perle Systems Limited"},
    {0x9753, "PEZY Computing K.K."},
    {0x1987, "Phison Electronics Corporation"},
    {0x1442, "Phoenix Contact Gmbh & Co. KG"},
    {0x1363, "Phoenix Technologies"},
    {0x115C, "Photron Ltd."},
    {0x1761, "Pickering Interfaces Ltd."},
    {0x1718, "Pixela Corporation"},
    {0x1556, "PLDA"},
    {0x1C79, "Plexus Corp."},
    {0x1D7F, "Plugable"},
    {0x11F8, "PMC-Sierra Inc."},
    {0x15BB, "Portwell Inc"},
    {0x1D51, "Powerleader Science & Technology Co. Ltd"},
    {0x1C67, "PreSonus Audio Electronics Inc."},
    {0x1D10, "Procera Networks, Inc."},
    {0x1C72, "ProDesign Electronic GmbH"},
    {0x105A, "Promise Technology, Inc."},
    {0x19D5, "Protech Systems"},
    {0x17C3, "Protogate, Inc."},
    {0x1D00, "Pure Storage, Inc."},
    {0x1077, "QLogic Corp."},
    {0x1BAA, "QNAP Systems, Inc."},
    {0x1E34, "Qrypt, Inc."},
    {0x1A9D, "QSC Audio Products, Inc."},
    {0x17CB, "Qualcomm"},
    {0x1969, "Qualcomm Atheros"},
    {0x168C, "Qualcomm Atheros"},
    {0x5143, "Qualcomm Inc."},
    {0x152D, "Quanta Computer Inc."},
    {0x1BB5, "Quantenna Communications, Inc."},
    {0x1D64, "Quarch Technology Ltd"},
    {0x11E3, "Quicklogic Corporation"},
    {0x19D4, "Quixant Plc"},
    {0x1CC6, "Radian Memory Systems Inc."},
    {0x186F, "Radixon Group Pty Ltd."},
    {0x1195, "Ratoc Systems Inc."},
    {0x10B2, "Raytheon Company"},
    {0x1A58, "Razer Inc."},
    {0x17F3, "RDC Semiconductor Co., Ltd."},
    {0x10EC, "Realtek Semiconductor Corporation"},
    {0x1B36, "Red Hat, Inc."},
    {0x17D2, "Red Rapids"},
    {0x1960, "REJ Co., Ltd."},
    {0x1912, "Renesas Electronics Corporation"},
    {0x163F, "Renishaw PLC"},
    {0x1180, "Ricoh Company, Ltd."},
    {0x1D76, "Rincon Research Corporation"},
    {0x1B2E, "Riverbed Technology, Inc."},
    {0x1D18, "RME GmbH"},
    {0x12A0, "Rockwell Automation Inc. (Allen-Bradley)"},
    {0x15D7, "Rockwell Collins, Inc."},
    {0x162F, "Rohde & Schwarz Gmbh & Co Kg"},
    {0x10DB, "Rohm Co., Ltd."},
    {0x16CE, "Roland Corporation"},
    {0x1B6B, "Roper Scientific dba Photometrics, dba Qimaging"},
    {0x1CBF, "Ross Video"},
    {0x1DF4, "ROW6, Inc."},
    {0x1435, "RTD Embedded Technologies, Inc."},
    {0x1B86, "Saab AB"},
    {0x16AE, "SafeNet, Inc."},
    {0x1DD3, "Sage Microelectronics Corp."},
    {0x1E0D, "SambaNova Systems, Inc."},
    {0x144D, "Samsung Electronics Co., Ltd."},
    {0x1A82, "Samtec Inc."},
    {0x1923, "Sangoma Technologies Corporation"},
    {0x1CC3, "Sanmina"},
    {0x1380, "Sanritz Automation Co., Ltd."},
    {0x194D, "Sansei System Co., Ltd."},
    {0x1DA2, "Sapphire Technology Limited"},
    {0x174F, "SAXA, Inc."},
    {0xCC53, "ScaleFlux Inc."},
    {0x8686, "ScaleMP"},
    {0x1C2E, "Schneider Electric Japan Holdings Ltd."},
    {0x1AA9, "Schweitzer Engineering Labs, Inc."},
    {0x1D60, "Scietera Technologies, Inc"},
    {0x11C6, "SCREEN GRAPHIC SOLUTIONS CO., LTD."},
    {0x1BB1, "Seagate Technology LLC"},
    {0x1A0D, "SEAKR Engineering Inc."},
    {0x135E, "Sealevel Systems, Inc."},
    {0x1BEC, "SECO Srl"},
    {0x1CDD, "Secunet Security Networks AG"},
    {0x11DB, "Sega Corporation"},
    {0x1CB4, "SerialTek"},
    {0x1E27, "Shanghai Denglin Technology Co., Ltd"},
    {0x1E36, "Shanghai Enflame Technology Co. Ltd"},
    {0x1E2A, "Shanghai JYTEK Co., Ltd"},
    {0x1D17, "Shanghai Zhaoxin Semiconductor Co., Ltd."},
    {0x1CB0, "Shannon Systems"},
    {0x1D08, "Shen Zhen Deren Electronic Co., LTD."},
    {0x8009, "Shengli Financial Software Development Co.Ltd"},
    {0x1642, "Shenzhen Bitland Information Technology Co., Ltd"},
    {0x1E3B, "Shenzhen DAPU Microelectronics Co., Ltd"},
    {0x1E0B, "Shenzhen Decenta Technology Co.,LTD"},
    {0x4C52, "Shenzhen Lianrui Electronics Co.,Ltd"},
    {0x1D97, "Shenzhen Longsys Electronics Co., Ltd."},
    {0x1DF5, "ShenZhen TIGO Semiconductor Co., Ltd."},
    {0x1CC4, "Shenzhen Unionmemory information system limited"},
    {0x1C37, "Shikino High-Tech Co., Ltd"},
    {0x1C71, "Shimadzu Corporation"},
    {0x110A, "Siemens AG"},
    {0x18D7, "Sierra Wireless, Inc."},
    {0xF15E, "SiFive, Inc."},
    {0x1BE9, "Signal Integrity Software, Inc."},
    {0x1BEB, "SignalCore, Inc."},
    {0x131F, "SIIG, Inc."},
    {0x1BCE, "Silex Technology, Inc."},
    {0x1374, "SiLicom, Ltd"},
    {0x1E14, "Silicon Creations, LLC"},
    {0xA23B, "Silicon Integrated Systems"},
    {0x1543, "Silicon Labs"},
    {0x126F, "Silicon Motion, Inc."},
    {0x1AE8, "Silicon Software GmbH"},
    {0x1DF9, "Simula Technology Inc."},
    {0x1C5C, "SK Hynix"},
    {0x1A4A, "SLAC National Accelerator Lab PPA-REG"},
    {0x1235, "SMART Modular Technologies"},
    {0x1CDF, "SmartDV North America, LLC"},
    {0x1E4F, "Smiths Interconnect"},
    {0x50C1, "Socionext Inc."},
    {0x8322, "Sodick America Corporation"},
    {0x14A0, "Softing AG"},
    {0x1924, "Solarflare Communications, Inc."},
    {0x1D1E, "Solid State System"},
    {0x1BC9, "Sonifex Ltd"},
    {0x104D, "Sony Corporation"},
    {0x1E31, "SORD Corporation"},
    {0x1BB8, "Space Exploration Technologies"},
    {0x1DAC, "SparkLAN Communications, Inc."},
    {0x1E41, "Spectra7 Microsystems"},
    {0x18F1, "Spectrum Instrumentation GmbH"},
    {0x174A, "Spirent Communications"},
    {0x1DB3, "Spreadtrum Communications (Shanghai) Co., Ltd."},
    {0x1E24, "Squirrels, Inc"},
    {0x191E, "SRISA"},
    {0x1DC7, "SSI Computer Corp"},
    {0x1A8A, "Star Bridge, Inc."},
    {0x1BCA, "Star Communications, Inc."},
    {0x1974, "STAR Electronics GmbH & Co. KG"},
    {0x1B5E, "Star-Dundee Ltd."},
    {0x1B45, "StarTech.com Ltd."},
    {0x104A, "STMicroelectronics International NV"},
    {0x1D63, "StorArt Technology Co., Ltd"},
    {0x159C, "Stratus Technologies, Inc."},
    {0x1CF7, "Subspace Dynamics LLC"},
    {0x1FD4, "Sunix Co., Ltd."},
    {0x15D9, "Super Micro Computer Inc."},
    {0x1E0E, "Suruga Seiki Co.,Ltd."},
    {0x1DD4, "Swissbit AG"},
    {0x15E0, "Symantec (Canada) Corp."},
    {0x1E01, "Synaptics, Inc."},
    {0x1CA1, "Sync-n-Scale, LLC"},
    {0x16C3, "Synopsys, Inc."},
    {0x184B, "SYSTEC Corporation"},
    {0x1E47, "SZ DJI Technology Co., Ltd."},
    {0x1B80, "T-Systems International GmbH"},
    {0x1BF7, "T.P.A. s.p.a."},
    {0x1A12, "Taiwan Commate Computer"},
    {0x1CEB, "Taiwan Pulse Motion Co., Ltd."},
    {0x12AF, "TDK Corporation"},
    {0x1513, "TE Connectivity"},
    {0x1A9F, "Tech S.A.T. GmbH"},
    {0x1D61, "Technobox, Inc."},
    {0x1C4E, "Techway"},
    {0x1DA1, "Teko Telecom S.r.l. a Socio Unico"},
    {0x1DE1, "Tekram Technology Co.,Ltd."},
    {0x10E1, "Tekram Technology Co.,Ltd."},
    {0x16A5, "Tekram Technology Co.,Ltd."},
    {0x1268, "Tektronix"},
    {0x1D88, "Telechips Inc."},
    {0x1570, "Teledyne LeCroy"},
    {0x1B37, "Teledyne SP Devices"},
    {0x13E5, "Telesoft Technologies Ltd."},
    {0x1C5D, "Telit Communications SPA"},
    {0x1E52, "Tenstorrent Inc"},
    {0x6549, "Teradici Corporation"},
    {0x1316, "Teradyne, Inc."},
    {0x1DCC, "TERMINUS CIRCUITS Pvt Ltd"},
    {0x1E37, "Testmetrix Inc"},
    {0x1498, "TEWS Technologies GmbH"},
    {0x104C, "Texas Instruments"},
    {0x1269, "Thales"},
    {0x1BD5, "The FreeBSD Foundation"},
    {0x1E38, "ThinCI, Inc."},
    {0x1168, "Thine Electronics, Inc."},
    {0x1E40, "ThinkRF Corp."},
    {0x1DDD, "Thorlabs, Inc."},
    {0x1E2F, "Tiburn Technology Co., Ltd."},
    {0x1D72, "Timi Personal Computing Co., Ltd."},
    {0x14D2, "TITAN Electronics Inc."},
    {0x1BC8, "Tokushu Denshi Kairo Inc."},
    {0x1679, "Tokyo Electron Device Ltd."},
    {0x138B, "TOKYO KEIKI INC."},
    {0x1E22, "Tongfang Computer Co.,Ltd"},
    {0x1D05, "TONGFANG HONGKONG LIMITED"},
    {0x1D31, "TOSEI ENGINEERING CORP."},
    {0x1179, "Toshiba Corporation"},
    {0x1E0F, "Toshiba Memory Corporation"},
    {0x1D79, "Transcend Information, Inc."},
    {0x11D7, "Trenton Systems, Inc."},
    {0x1A3D, "Tritek Co., Ltd."},
    {0x1C64, "TRS-RenTelco"},
    {0x1DAB, "Tsinghua University"},
    {0x189E, "TSMC"},
    {0x1C7E, "TTTech Computertechnik AG"},
    {0x148C, "Tul Corporation"},
    {0x1E32, "Tuxera Inc."},
    {0x14FF, "Twinhead International Corporation"},
    {0x1ADD, "u-blox AG"},
    {0x1E51, "UAB Neurotechnologijos"},
    {0x0A7C, "UATC, LLC"},
    {0x19BC, "Ueda Japan Radio Co., Ltd."},
    {0x1D44, "ULINK Technology, Inc."},
    {0x18D1, "ULVAC-PHI, Inc."},
    {0x1C1A, "UNH InterOperability Laboratory"},
    {0x1D78, "UNIC Memory Technology Co., Ltd."},
    {0x19BF, "Unicom Engineering Inc"},
    {0x1018, "Unisys Corporation"},
    {0x1DC9, "UniTest Inc."},
    {0x1A00, "Universal Audio, Inc."},
    {0x14CD, "Universal Global Scientific Industrial Co., Ltd"},
    {0x1DA5, "UTran Technology Inc."},
    {0x1DF8, "V&G Information System Co.,Ltd"},
    {0xABCD, "Vadatech Inc."},
    {0x1D19, "VAIO Corporation"},
    {0x1DDE, "Valens Semiconductor Ltd."},
    {0x1E44, "Valve Software"},
    {0x1E1C, "Vanguard Rugged Storage, LLC"},
    {0x1FCB, "Varex Imaging Deutschland AG"},
    {0x1E46, "Varjo Technologies Oy"},
    {0x1DAE, "Vectology,Inc."},
    {0x19E2, "Vector Informatik GmbH"},
    {0x144B, "Verint"},
    {0x1106, "VIA Technologies, Inc."},
    {0x1D7D, "Viavi Solutions"},
    {0x1E07, "ViGEM GmbH"},
    {0x1C60, "Viking Technology"},
    {0x1DF0, "Virtuozzo International GmbH"},
    {0x156C, "VMagic Electronics GmbH"},
    {0x15AD, "Vmware, Inc."},
    {0x5658, "VX Instruments GmbH"},
    {0x1DC8, "Wave Computing, Inc."},
    {0x1B96, "Western Digital Technologies, Inc."},
    {0x1C6C, "Wibtek Electronics Co., Ltd"},
    {0x1E15, "Wieson Technologies Co., LTD."},
    {0x1CCE, "Wilder Technologies"},
    {0x1B17, "WinSystems, Inc."},
    {0x1811, "Wipro Technologies"},
    {0x17C0, "Wistron Corporation"},
    {0x301F, "WOLF Advanced Technology"},
    {0x10C5, "Xerox Corporation"},
    {0x1C40, "Xia LLC"},
    {0x10EE, "Xilinx, Inc."},
    {0xDEDA, "XIMEA"},
    {0x1C5B, "XJTAG Ltd."},
    {0x1D93, "YADRO"},
    {0x1073, "Yamaha Corporation"},
    {0x18B4, "Yamaichi Electronics"},
    {0x150B, "Yamashita Systems Corp"},
    {0x1E49, "Yangtze Memory Technologies Co.,Ltd"},
    {0x1313, "YASKAWA Electric Corporation"},
    {0x1281, "Yokogawa Electric Corporation"},
    {0x1D6B, "ZAO Kraftway Corporation PLC"},
    {0x1E21, "ZF Friedrichshafen AG"},
    {0x1CCF, "Zoom Corporation"},
};
