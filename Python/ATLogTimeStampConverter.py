"""
An epoch time stamp converter for cell AT logs
"""

import argparse
import os
from time import sleep
from datetime import datetime
from datetime import timedelta


TIME_ZONE_OFFSET_FROM_UTC = {
    "GMT": 0.0,
    "EST": -4.0,
    "PST": -7.00,
    "CST": -5.0,
}


# main
#
# @brief  - Parses and converts epoch time to YYYY:MM:DD HH:DD:SS
#           if each line in the input doc starts with linux epoch tine
# param   - path in which the file needs to be parsed exists
# param   - time_zone to which the epoch time needs to be converted
# param   - input_filename name of the file that needs to be converted
# param   -  output_filename name of the output file that will be generated
# @return - None
#

def parse_at_logfile(dir_name, time_zone, input_filename, output_filename):
    assert os.path.exists(dir_name)
    input_file_path = os.path.join(dir_name, input_filename)
    assert os.path.exists(input_file_path)
    output_file_path = os.path.join(dir_name, output_filename)
    output_file = open(output_file_path, "w")
    with open(input_file_path) as f:
        lines = f.readlines()
        for line in lines:
            split_line = line.split(" : ")
            print(line)
            # Covert from epoch to YYYY:MM:DD HH:DD:SS format
            human_date_time = datetime.fromtimestamp(
                float(split_line[0].split(".")[0]))

            #Adjust the time zone offset
            human_date_time += timedelta(
                hours=TIME_ZONE_OFFSET_FROM_UTC[time_zone])

            # write line to the output file 
            output_file.write(str(human_date_time)+" : " + split_line[1])

    output_file.close()


# main
#
# @brief  - Parses input arguments, creates a CAN interface
#           and calls the test case
# @return - None
#

if __name__ == "__main__":

    # Parse command line arguments
    Parser = argparse.ArgumentParser(usage=__doc__)
    Parser.add_argument("-d", "--dir", type=str,
                        default=os.getcwd(), help="Provide dir path to the file")
    Parser.add_argument("-f", "--input_filename", type=str,
                        default="AT.log", help="Provide the input filename")
    Parser.add_argument("-o", "--output_filename", type=str,
                        default="AT_Output.log", help="Provide the output filename")
    Parser.add_argument('-z', '--time_zone', type=str, default='GMT',
                        choices=['EST', 'PST', 'GMT', 'CST'],
                        help='Time Zone')

    Opts = Parser.parse_args()
    parse_at_logfile(Opts.dir, Opts.time_zone, Opts.input_filename, Opts.output_filename)
