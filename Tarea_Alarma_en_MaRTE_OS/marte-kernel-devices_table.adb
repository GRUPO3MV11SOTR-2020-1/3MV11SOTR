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
--  File 'k-devices_table.adb                                    By Fguerreira
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

with MaRTE.Configuration_Parameters;
with MaRTE.Direct_IO; use MaRTE.Direct_IO;

package body MaRTE.Kernel.Devices_Table is

   --------------------------
   --  Initialize_Devices  --
   --------------------------
   procedure Initialize_Devices is
      use type Int;
   begin
      if MaRTE.Configuration_Parameters.Use_Devices_Filesystem then
         Put ("Devices initialization..."); New_Line;
         for I in Major loop
            if The_Driver_Table (I).Create /= null then
               Put ("   Major Number "); Put (Integer (I));
               case I is
                  when 1 =>      Put (" (stdin)  ");
                  when 2 =>      Put (" (stdout) ");
                  when 3 =>      Put (" (stderr) ");
                  when 5 =>      Put (" (lpt0)   ");
                  when others => Put ("          ");
               end case;
               Put (The_Driver_Table (I).Name);
               if The_Driver_Table (I).Create.all = 0 then
                  Put ("...OK");
               else
                  Put ("...*** FAIL!! ***");
               end if;
               New_Line;
            end if;
         end loop;
      end if;
   end Initialize_Devices;

end MaRTE.Kernel.Devices_Table;
