#!/bin/bash
#PBS -l ncpus=1
#PBS -l pmem=7gb
#PBS -l walltime=10:00:00
#PBS -d .
#PBS -j oe
#PBS -o /mal2/wammar/exp/tgt-rep/align/example/small.pbs.log

#python utils/encode-corpus.py example/iwslt12.eng example/iwslt12.eng.vocab example/iwslt12.eng.int
#python utils/encode-corpus.py example/iwslt12.trk example/iwslt12.trk.vocab example/iwslt12.trk.int
make
./train-model1 example/iwslt12.eng.int example/iwslt12.trk.int example/iwslt12.out
#head example/medium.out.param.final
#awk '{print $1}' example/medium.out.param.final > example/medium.out.param.final.eng
#awk '{print "$2 $4"}' example/medium.out.param.final > example/medium.out.param.final.kin
#python utils/decode-corpus.py example/medium.eng.vocab example/medium.out.param.final.eng example/medium.out.param.final.eng.text
#./train-loglinear example/small.eng.int example/small.kin.int example/small.out