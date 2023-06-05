pipeline {
	agent any
	stages{
		stage('Build'){
			steps{
				sh 'echo "Building.."'
				sh 'chmod +x scripts/Linux-Build.sh'
				sh 'scripts/Linux-Build.sh'
				archiveArtifacts artifacts: '*', fingerprint: true
			}
	}
	stage('Test 1-8'){
		steps{
			sh 'echo "Running 1-8..."'
			sh './src/build/exec'

		}
	}
	stage('Test 9'){
		steps{
			sh 'echo "Running 9..."'
			sh 'chmod +x scripts/Linux-Run2.sh'
			sh 'scripts/Linux-Run2.sh'

		}
	}
	stage('Test 10'){
		steps{
			sh 'echo "Running 10..."'
			sh 'scripts/Linux-Run3.sh'
		}
	}
	stage('Run main'){
		steps{
			sh 'echo "Running main..."'
			sh 'scripts/Linux-RunMain.sh'		
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
