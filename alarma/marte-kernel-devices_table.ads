------------------------------------------------------------------------------
-- --------------------        M a R T E   O S          ------------------- --
------------------------------------------------------------------------------
--                                                             V2.0 2017-02-22
--
--                ' K e r n e l . D e v i c e s _ T a b l e'
--
--                                    Spec
--
--
--  File 'k-devices_table.ads                                    By Fguerreira
--
--  This is the x86 architecture version of this package.
--
--  Table definition where all the drivers are loaded.
--
--  To add a new device to the system you should add a new entry in
--  the "Drivers table" and at least one new device file in the "Device
--  files table".
--
--  ----------------------------------------------------------------------
--   Copyright (C) 2000-2017, Universidad de Cantabria, SPAIN
--
--   MaRTE OS web page: http://marte.unican.es
--   Contact Addresses: Mario Aldea Rivas          aldeam@unican.es
--                      Michael Gonzalez Harbour      mgh@unican.es
--
--  MaRTE OS  is free software; you can  redistribute it and/or  modify it
--  under the terms of the GNU General Public License  as published by the
--  Free Software Foundation;  either  version 2, or (at  your option) any
--  later version.
--
--  MaRTE OS  is distributed  in the  hope  that  it will be   useful, but
--  WITHOUT  ANY  WARRANTY;     without  even the   implied   warranty  of
--  MERCHANTABILITY  or  FITNESS FOR A  PARTICULAR PURPOSE.    See the GNU
--  General Public License for more details.
--
--  You should have received  a  copy of  the  GNU General Public  License
--  distributed with MaRTE  OS;  see file COPYING.   If not,  write to the
--  Free Software  Foundation,  59 Temple Place  -  Suite 330,  Boston, MA
--  02111-1307, USA.
--
--  As a  special exception, if you  link this  unit  with other  files to
--  produce an   executable,   this unit  does  not  by  itself cause  the
--  resulting executable to be covered by the  GNU General Public License.
--  This exception does  not however invalidate  any other reasons why the
--  executable file might be covered by the GNU Public License.
------------------------------------------------------------------------------

--  Typical standard devices (standard input, output and error)
with Keyboard_Functions;          --  standard input
pragma Elaborate (Keyboard_Functions);
--  with Text_Console_Driver_Import;  --  standard output and error
with Console_Switcher_Import;  --  standard output and error
--  with Serial_Port_Driver_Import;  --  standard output and error

--  User's drivers "withs" (add line 'with {your_driver}')
--  with Dynamic_Buffer_Driver.Functions;
--  with Serial_Port_Driver_Import;
 with Printer_Port_Functions;
pragma Elaborate(Printer_Port_Functions);
-- with Ethernet;
with Demo_Driver_Ada_Functions;
 with Demo_Driver_C_Import;
--  with Fat_Driver_Functions;
--  pragma Elaborate (Fat_Driver_Functions);
--  with pcm3718_functions;
--  with cmps03_functions;
 with Membuffer_Driver_Import;
--  with CAN_Driver_Import;
--  with PS2_Mouse.Functions;

--  MaRTE OS "withs" (Do not edit)
pragma Elaborate (Demo_Driver_Ada_Functions);

with MaRTE.Kernel.File_System_Data_Types;
use MaRTE.Kernel.File_System_Data_Types;

package MaRTE.Kernel.Devices_Table is
   package K renames MaRTE.Kernel;

   ---------------------------------------------------------------------------
   --  Drivers Table  --------------------------------------------------------
   ---------------------------------------------------------------------------
   --
   --  Device drivers included in the system. This table associates
   --  major numbers with device drivers. To include a driver just add
   --  the following lines to the table:
   --
   --  any major number available => (
   --  {your_driver}_create'access,
   --  {your_driver}_remove'access,
   --  {your_driver}_open'access,
   --  {your_driver}_close'access,
   --  {your_driver}_read'access,
   --  {your_driver}_write'access,
   --  {your_driver}_ioctl'access etc ...)
   --
   --  For your driver you can use any major number not in use, for
   --  example, if you are not using serial ports, major number 4 is
   --  free to be used in any other driver.
   --
   --  Major numbers are in range (1
   --  .. Configuration_Parameters.Devices_Files_Mx). In case you need
   --  a wider range, modify Devices_Files_Mx constant (file
   --  configuration_parameters.ads) and recompile MaRTE OS as
   --  explained in the user's guide (marte_ug.html).

   The_Driver_Table :  K.File_System_Data_Types.Driver_Table_Type :=
     (
      --  Standard Input
      --  DO NOT COMMENT OUT. If you don't want to use this device
      --  just set all entries to 'null'.
      --  If you modify this device, you should also change
      --  'Stdin_Direct_Read' in 'kernel_console.ads'.
      1 => (Name   => "Keyboard        ",
            Create => Keyboard_Functions.Create'Access,
            Remove => null,
            Open   => null,
            Close  => null,
            Read   => Keyboard_Functions.Read'Access,
            Write  => null,
            Ioctl  => Keyboard_Functions.Ioctl'Access,
            Delete => null,
            Lseek  => null),

      --  Standard Output
      --  DO NOT COMMENT OUT. If you don't want to use this device
      --  just set all entries to 'null'.
      --  If you modify this device, you should also change
      --  'Stdout_Basic_Init' and 'Stdout_Direct_Write' in
      --  'kernel_console.ads'.
      2 => (Name   => "Text/Serial     ",
            Create => Console_Switcher_Import.Create_Ac,
            Remove => Console_Switcher_Import.Remove_Ac,
            Open   => Console_Switcher_Import.Open_Ac,
            Close  => Console_Switcher_Import.Close_Ac,
            Read   => null,
            Write  => Console_Switcher_Import.Write_Ac,
            Ioctl  => Console_Switcher_Import.Ioctl_Ac,
            Delete => null,
            Lseek  => null),
      --  2 => (Name   => "Text Console    ",
      --        Create => Text_Console_Driver_Import.Create_Ac,
      --        Remove => Text_Console_Driver_Import.Remove_Ac,
      --        Open   => Text_Console_Driver_Import.Open_Ac,
      --        Close  => Text_Console_Driver_Import.Close_Ac,
      --        Read   => null,
      --        Write  => Text_Console_Driver_Import.Write_Ac,
      --        Delete  => null,
      --        Lseek  => null),

      --  Standard Error
      --  DO NOT COMMENT OUT. If you don't want to use this device
      --  just set all entries to 'null'.
      --  If you modify this device, you should also change
      --  'Stderr_Basic_Init' and 'Stderr_Direct_Write' in
      --  'kernel_console.ads'.
      3 => (Name   => "Text/Serial     ",
            Create => Console_Switcher_Import.Create_Ac,
            Remove => Console_Switcher_Import.Remove_Ac,
            Open   => Console_Switcher_Import.Open_Ac,
            Close  => Console_Switcher_Import.Close_Ac,
            Read   => null,
            Write  => Console_Switcher_Import.Write_Error_Ac,
            Ioctl  => Console_Switcher_Import.Ioctl_Ac,
            Delete => null,
            Lseek  => null),
      --  3 => (Name   => "Text Console    ",
      --        Create => Text_Console_Driver_Import.Create_Ac,
      --        Remove => Text_Console_Driver_Import.Remove_Ac,
      --        Open   => Text_Console_Driver_Import.Open_Ac,
      --        Close  => Text_Console_Driver_Import.Close_Ac,
      --        Read   => null,
      --        Write  => Text_Console_Driver_Import.Write_Ac,
      --        Ioctl  => Text_Console_Driver_Import.Ioctl_Ac,
      --        Delete => null,
      --        Lseek  => null),

      --  Serial Ports
      --  4 => (Name   => "Serial ports    ",
      --        Create => Serial_Port_Driver_Import.Create_Ac,
      --        Remove => Serial_Port_Driver_Import.Remove_Ac,
      --        Open   => Serial_Port_Driver_Import.Open_Ac,
      --        Close  => Serial_Port_Driver_Import.Close_Ac,
      --        Read   => Serial_Port_Driver_Import.Read_Ac,
      --        Write  => Serial_Port_Driver_Import.Write_Ac,
      --        Ioctl  => Serial_Port_Driver_Import.Ioctl_Ac,
      --        Delete => null,
      --        Lseek  => null),

      --  Printer Port
       5 => (Name   => "Printer Port    ",
              Create => Printer_Port_Functions.Create'Access,
              Remove => null,
              Open   => null,
              Close  => null,
              Read   => Printer_Port_Functions.Read'Access,
              Write  => Printer_Port_Functions.Write'Access,
              Ioctl  => Printer_Port_Functions.Ioctl'Access,
              Delete => null,
              Lseek  => null),

      --  Generic Ethernet Card (Sis900, Intel EtherExpresss 100 or RTL8139)
      --  6 => (Name   => "Ether Drv       ",
      --        Create => Ethernet.Create_Ac,
      --        Remove => null,
      --        Open   => Ethernet.Open_Ac,
      --        Close  => Ethernet.Close_Ac,
      --        Read   => Ethernet.Read_Ac,
      --        Write  => Ethernet.Write_Ac,
      --        Ioctl  => Ethernet.Ioctl_Ac,
      --        Delete => null,
      --        Lseek  => null),

      --  Dynamic Buffer
      --  7 => (Name   => "Dynamic Buffer  ",
      --       Create => Dynamic_Buffer_Driver.Functions.Create'Access,
      --       Remove => Dynamic_Buffer_Driver.Functions.Remove'Access,
      --       Open   => Dynamic_Buffer_Driver.Functions.Open'Access,
      --       Close  => Dynamic_Buffer_Driver.Functions.Close'Access,
      --       Read   => Dynamic_Buffer_Driver.Functions.Read'Access,
      --       Write  => Dynamic_Buffer_Driver.Functions.Write'Access,
      --       Ioctl  => Dynamic_Buffer_Driver.Functions.Ioctl'Access,
      --       Delete => null,
      --       Lseek  => null),

      --  Demo Driver Ada
      --  x => (Name   => "Demo Driver Ada ",
      --        Create => Demo_Driver_Ada_Functions.Create'Access,
      --        Remove => Demo_Driver_Ada_Functions.Remove'Access,
      --        Open   => Demo_Driver_Ada_Functions.Open'Access,
      --        Close  => Demo_Driver_Ada_Functions.Close'Access,
      --        Read   => Demo_Driver_Ada_Functions.Read'Access,
      --        Write  => Demo_Driver_Ada_Functions.Write'Access,
      --        Ioctl  => Demo_Driver_Ada_Functions.Ioctl'Access,
      --        Delete => null,
      --        Lseek  => null),

      --  Demo Driver C
      --  X => (Name   => "Demo Driver C   ",
      --        Create => Demo_Driver_C_Import.Create_Ac,
      --        Remove => Demo_Driver_C_Import.Remove_Ac,
      --        Open   => Demo_Driver_C_Import.Open_Ac,
      --        Close  => Demo_Driver_C_Import.Close_Ac,
      --        Read   => Demo_Driver_C_Import.Read_Ac,
      --        Write  => Demo_Driver_C_Import.Write_Ac,
      --        Ioctl  => Demo_Driver_C_Import.Ioctl_Ac,
      --        Delete => null,
      --        Lseek  => null),

      --  Fat driver
      --  9 => (Name   => "FAT Driver      ",
      --        Create => Fat_Driver_Functions.Create'Access,
      --        Remove => null,
      --        Open   => Fat_Driver_Functions.Open'Access,
      --        Close  => null,
      --        Read   => Fat_Driver_Functions.Read'Access,
      --        Write  => Fat_Driver_Functions.Write'Access,
      --        Ioctl  => null,
      --        Delete => Fat_Driver_Functions.Delete'Access,
      --        Lseek  => Fat_Driver_Functions.Lseek'Access),

      --  PCM3718_Digital_Inpue-output
      --  10 => (Name   => "pcm3718 DIO     ",
      --         Create => null,
      --         Remove => null,
      --         Open   => pcm3718_Functions.Dio_Open'Access,
      --         Close  => pcm3718_Functions.Dio_Close'Access,
      --         Read   => pcm3718_Functions.Dio_Read'Access,
      --         Write  => pcm3718_Functions.Dio_Write'Access,
      --         Ioctl  => pcm3718_Functions.Dio_Ioctl'Access,
      --         Delete => null,
      --         Lseek  => null),

      --  PCM3718_Analog_Input
      --  11 => (Name   => "pcm3718 AI      ",
      --         Create => null,
      --         Remove => null,
      --         Open   => pcm3718_Functions.Ai_Open'Access,
      --         Close  => pcm3718_Functions.Ai_Close'Access,
      --         Read   => pcm3718_Functions.Ai_Read'Access,
      --         Write  => null,
      --         Ioctl  => pcm3718_Functions.Ai_Ioctl'Access,
      --         Delete => null,
      --         Lseek  => null),

      --  CMPS03 through i2c protocol
      --  12 => (Name   => "CMPS03_compass  ",
      --         Create => cmps03_Functions.Create_Ac,
      --         Remove => cmps03_Functions.Remove_Ac,
      --         Open   => cmps03_Functions.Open_Ac,
      --         Close  => cmps03_Functions.Close_Ac,
      --         Read   => cmps03_Functions.Read_Ac,
      --         Write  => null,
      --         Ioctl  => cmps03_Functions.Ioctl_Ac,
      --         Delete => null,
      --         Lseek  => null),

      --  Circular Buffer
      --  13 => (Name   => "Circular Buffer ",
      --         Create => Membuffer_Driver_Import.Create_Ac,
      --         Remove => Membuffer_Driver_Import.Remove_Ac,
      --         Open   => null,
      --         Close  => null,
      --         Read   => Membuffer_Driver_Import.Read_Ac,
      --         Write  => Membuffer_Driver_Import.Write_Ac,
      --         Ioctl  => null,
      --         Delete => null,
      --         Lseek  => null),

      --  CAN driver
      --  14 => (Name   => "CAN driver      ",
      --         Create => CAN_Driver_Import.Create_Ac,
      --         Remove => CAN_Driver_Import.Remove_Ac,
      --         Open   => CAN_Driver_Import.Open_Ac,
      --         Close  => CAN_Driver_Import.Close_Ac,
      --         Read   => CAN_Driver_Import.Read_Ac,
      --         Write  => CAN_Driver_Import.Write_Ac,
      --         Ioctl  => CAN_Driver_Import.Ioctl_Ac,
      --         Delete => null,
      --         Lseek  => null),

      --  PS/2 Mouse
      --  15 => (Name   => "PS/2 Mouse      ",
      --         Create => PS2_Mouse.Functions.Create'Access,
      --         Remove => null,
      --         Open   => null,
      --         Close  => null,
      --         Read   => PS2_Mouse.Functions.Read'Access,
      --         Write  => null,
      --         Ioctl  => PS2_Mouse.Functions.Ioctl'Access,
      --         Delete => null,
      --         Lseek  => null),

      others =>
         ("                ",
         null, null, null, null, null, null, null, null, null));

   ---------------------------------------------------------------------------
   --  Device files table  ---------------------------------------------------
   ---------------------------------------------------------------------------
   --
   --  This table defines the files in the file-system. To create a new
   --  file, add a new entry to the table using the appropriate
   --  parameters:
   --
   --  The major number must be the one that points to the driver in
   --  The_Driver_Table rows
   --
   --  The minor number may be anyone, as it's used as a minor number
   --  to differentiate assignments of the same Major_Number
   --
   --  The Boolean indicates whether the assignment is in use or not

   The_Device_Files_Table :
     K.File_System_Data_Types.Device_Files_Table_Type :=
     (
      --        File path  Major  Minor   Used   Type   Del  Count
      --  Standard files. DO NOT COMMENT OUT
      1  => ("/dev/stdin      ", 1, 0, True, Device, False, 0),
      2  => ("/dev/stdout     ", 2, 0, True, Device, False, 0),
      3  => ("/dev/stderr     ", 3, 0, True, Device, False, 0),
      --  User defined files
      --  4  => ("/dev/ttyS0      ", 4, 0, True, Device, False, 0),
      --  5  => ("/dev/ttyS1      ", 4, 1, True, Device, False, 0),
      --  6  => ("/dev/ttyS2      ", 4, 2, True, Device, False, 0),
      --  7  => ("/dev/ttyS3      ", 4, 3, True, Device, False, 0),
      8  => ("/dev/lpt0       ", 5, 0, True, Device, False, 0),
      --  9  => ("/dev/eth0       ", 6, 0, True, Device, False, 0),
      --  10 => ("/dev/buffer     ", 7, 0, True, Device, False, 0),
      --  11 => ("/dev/demo_ada   ", X, 0, True, Device, False, 0),
      --  12 => ("/dev/demo_c     ", X, 0, True, Device, False, 0),
      --  13 => ("/fat/           ", 9, 0, True, Mount_Point, False, 0),
      --  14 => ("/dev/dio        ", 10, 0, True, Device, False, 0),
      --  15 => ("/dev/daq        ", 11, 0, True, Device, False, 0),
      --  16 => ("/dev/cmps03     ", 12, 0, True, Device, False, 0),
      --  17 => ("/dev/membuff    ", 13, 0, True, Device, False, 0),
      --  18 => ("/dev/can0       ", 14, 0, True, Device, False, 0),
      --  19 => ("/dev/can1       ", 14, 1, True, Device, False, 0),
      --  20 => ("/dev/ps2mouse   ", 15, 0, True, Device, False, 0),
      others => ("                ", 9, 0, False, Device, False, 0)
      );

   --------------------------
   --  Initialize_Devices  --
   --------------------------
   procedure Initialize_Devices;

end MaRTE.Kernel.Devices_Table;
