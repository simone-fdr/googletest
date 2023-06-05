pipeline {
	agent any
	stages{
		stage('Build'){
			steps{
				sh 'echo "Building.."'
				sh 'chmod +x scripts/Linux-Build.sh'
				sh 'scripts/Linux-Build.sh'
				//sh 'mkdir scripts/src/build'
				//sh 'cd scripts/src/build'
				//sh 'cmake ..'
				//sh 'make'
				archiveArtifacts artifacts: '*', fingerprint: true
			}
	}
	stage('Test 1-8'){
		steps{
			sh 'echo "Running 1-8..."'
			//sh 'chmod +x scripts/Linux-Run1.sh'
			//sh 'scripts/Linux-Run1.sh'
			sh 'cd src/build'
			sh './exec'
		}
	}
	stage('Test 9'){
		steps{
			sh 'echo "Running 9..."'
			//sh 'chmod +x scripts/Linux-Run2.sh'
			//sh 'scripts/Linux-Run2.sh'
			sh 'cd src/build'
			sh './exec2'
		}
	}
	stage('Test 10'){
		steps{
			sh 'echo "Running 10..."'
			//sh 'chmod +x scripts/Linux-Run3.sh'
			//sh 'scripts/Linux-Run3.sh'
			sh 'cd src/build'
			sh './exec3'
		}
	}
	stage('Run main'){
		steps{
			sh 'echo "Running main..."'
			//sh 'chmod +x scripts/Linux-RunMain.sh'
			//sh 'scripts/Linux-RunMain.sh'		
			sh 'cd src/build'
			sh './main matrix.txt'
		}
	}
	stage('Build Docker'){
		steps{
			script{
				sh 'docker build -t simone-fdr/googletest .'
			}
		}
	}
	stage('Push Docker'){
		steps{
			withCredentials([string(credentialsId: 'dockerhub_pwd', variable: 'dockerhub_pwd')]) {
				sh 'docker login -u simone-fdr -p ${dockerhub_pwd}'
			}
			sh 'docker push filobuda/googletest'
		}
	}
}
}
